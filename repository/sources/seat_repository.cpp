//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../seat_repository.hpp"

void SeatRepository::insert(const Seat &seat) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into seats(cinema_room_id, row, place) values (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seat.cinema_room_id);
    sqlite3_bind_int(stmt, 2, seat.row);
    sqlite3_bind_int(stmt, 3, seat.place);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void SeatRepository::update(const int id, const Seat &seat) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update seats set cinema_room_id = ?, row = ?, place = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seat.cinema_room_id);
    sqlite3_bind_int(stmt, 2, seat.row);
    sqlite3_bind_int(stmt, 3, seat.place);
    sqlite3_bind_int(stmt, 4, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void SeatRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from seats where id = ?";
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

int SeatRepository::find_pos(const Seat &seat) {
    const std::string sql = "select id from seats where cinema_room_id = ? and row = ? and place = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seat.cinema_room_id);
    sqlite3_bind_int(stmt, 2, seat.row);
    sqlite3_bind_int(stmt, 3, seat.place);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return -1;
}

std::optional<std::unique_ptr<Seat>> SeatRepository::find_by_parameters(const int cinema_room_id, const int row, const int place) {
    const std::string sql = "select id from seats where cinema_room_id = ? and row = ? and place = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, cinema_room_id);
    sqlite3_bind_int(stmt, 2, row);
    sqlite3_bind_int(stmt, 3, place);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<Seat>(Seat{
                sqlite3_column_int(stmt, 0),
                cinema_room_id,
                row,
                place
        }));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}
