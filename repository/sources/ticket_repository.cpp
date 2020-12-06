//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../ticket_repository.hpp"

std::string TicketRepository::from_unsigned_char_to_std_string(const unsigned char *value) {
    std::string result = "";
    for (int i = 0; i < strlen(reinterpret_cast<const char*>(value)); ++i) {
        result += value[i];
    }
    return result;
}

void TicketRepository::insert(const Ticket &ticket) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into tickets(customer_id, seance_id, seat_id, price, state) values (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, ticket.customer_id);
    sqlite3_bind_int(stmt, 2, ticket.seance_id);
    sqlite3_bind_int(stmt, 3, ticket.seat_id);
    sqlite3_bind_int(stmt, 4, ticket.price);
    sqlite3_bind_text(stmt, 5, ticket.state.c_str(), -1, SQLITE_STATIC);
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
    sqlite3_bind_text(stmt, 5, ticket.state.c_str(), -1, SQLITE_STATIC);
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
                from_unsigned_char_to_std_string(sqlite3_column_text(stmt, 5))
        }));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}
