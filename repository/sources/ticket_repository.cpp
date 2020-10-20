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
