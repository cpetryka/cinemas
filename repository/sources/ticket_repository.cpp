//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../ticket_repository.hpp"

void TicketRepository::insert(const Ticket &ticket) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into tickets(customer_id, seance_id, seat_id, price, state) values (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, ticket.customer_id);
    sqlite3_bind_int(stmt, 2, ticket.seance_id);
    sqlite3_bind_int(stmt, 3, ticket.seat_id);
    sqlite3_bind_int(stmt, 4, ticket.price);
    std::string ticket_state_tmp = TicketState::to_string(ticket.state);
    sqlite3_bind_text(stmt, 5, ticket_state_tmp.c_str(), -1, SQLITE_STATIC);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void TicketRepository::update(const int id, const Ticket &ticket) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update tickets set customer_id = ?, seance_id = ?, seat_id = ?, price = ?, state = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, ticket.customer_id);
    sqlite3_bind_int(stmt, 2, ticket.seance_id);
    sqlite3_bind_int(stmt, 3, ticket.seat_id);
    sqlite3_bind_int(stmt, 4, ticket.price);
    std::string ticket_state_tmp = TicketState::to_string(ticket.state);
    sqlite3_bind_text(stmt, 5, ticket_state_tmp.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void TicketRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from tickets where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}


void TicketRepository::cancel_ticket_by_id(const int idx) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update tickets set state = 'CANCELLED' where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

std::vector<int> TicketRepository::find_reserved_seats(const int seance_id) {
    std::vector<int> reserved_seats;

    const std::string sql = "select seat_id from tickets where seance_id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance_id);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        reserved_seats.emplace_back(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return reserved_seats;
}

std::optional<std::unique_ptr<Ticket>> TicketRepository::find_by_id(const int idx) {
    const std::string sql = "select id, customer_id, seance_id, seat_id, price, state from tickets where id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<Ticket>(Ticket{
                sqlite3_column_int(stmt, 0),
                sqlite3_column_int(stmt, 1),
                sqlite3_column_int(stmt, 2),
                sqlite3_column_int(stmt, 3),
                sqlite3_column_int(stmt, 4),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 5))
        }));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::vector<int> TicketRepository::find_reservations_to_cancel() {
    std::vector<int> found_reservations;

    const std::string sql = "select t.id from tickets t join seances s on t.seance_id = s.id where t.state = 'RESERVED' and ((strftime('%s', s.date_time) - strftime('%s', ?)) between 0 and 1800)";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    auto current_date_and_time_str = DateTime().convert_date_and_time_into_string();
    sqlite3_bind_text(stmt, 1, current_date_and_time_str.c_str(), -1, 0);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        found_reservations.emplace_back(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return found_reservations;
}