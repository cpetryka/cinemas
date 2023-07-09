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
    auto ticket_state_str = TicketState::to_string(ticket.state); // Direct use does not work!
    sqlite3_bind_text(stmt, 5, ticket_state_str.c_str(), -1, SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
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
    auto ticket_state_str = TicketState::to_string(ticket.state); // Direct use does not work!
    sqlite3_bind_text(stmt, 5, ticket_state_str.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void TicketRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from tickets where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void TicketRepository::cancel_ticket_by_id(const int idx) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update tickets set state = 'CANCELLED' where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
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

    while (sqlite3_step(stmt) == SQLITE_ROW) {
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

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<Ticket>(
                sqlite3_column_int(stmt, 0),
                sqlite3_column_int(stmt, 1),
                sqlite3_column_int(stmt, 2),
                sqlite3_column_int(stmt, 3),
                sqlite3_column_int(stmt, 4),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 5))
        ));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::vector<std::unique_ptr<Ticket>> TicketRepository::find_all_by_customer_id(const int customer_id) {
    std::vector<std::unique_ptr<Ticket>> found_tickets;

    const std::string sql = "select id, customer_id, seance_id, seat_id, price, state from tickets where customer_id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, customer_id);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found_tickets.emplace_back(std::make_unique<Ticket>(
                sqlite3_column_int(stmt, 0),
                sqlite3_column_int(stmt, 1),
                sqlite3_column_int(stmt, 2),
                sqlite3_column_int(stmt, 3),
                sqlite3_column_int(stmt, 4),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 5))
        ));
    }

    sqlite3_finalize(stmt);
    return found_tickets;
}

std::vector<int> TicketRepository::find_reservations_to_cancel() {
    std::vector<int> found_reservations;

    const std::string sql = "select t.id from tickets t join seances s on t.seance_id = s.id where t.state = 'RESERVED' and ((strftime('%s', s.date_time) - strftime('%s', ?)) between 0 and 1800)";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, DateTimeUtils::get_current_date_and_time_as_string().c_str(), -1, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        found_reservations.emplace_back(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return found_reservations;
}