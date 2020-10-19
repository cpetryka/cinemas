//
// Created by Cezary Petryka on 19.10.2020.
//

#include "../cinema_room_repository.hpp"

void CinemaRoomRepository::insert(const CinemaRoom &cinema_room) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into cinema_rooms(name, cinema_id, rows, places) values (?, ?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema_room.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, cinema_room.cinema_id);
    sqlite3_bind_int(stmt, 3, cinema_room.rows);
    sqlite3_bind_int(stmt, 4, cinema_room.places);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CinemaRoomRepository::update(const int id, const CinemaRoom &cinema_room) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update cinema_rooms set name = ?, cinema_id = ?, rows = ?, places = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema_room.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, cinema_room.cinema_id);
    sqlite3_bind_int(stmt, 3, cinema_room.rows);
    sqlite3_bind_int(stmt, 4, cinema_room.places);
    sqlite3_bind_int(stmt, 5, id);
    const auto results = sqlite3_step(stmt);

    if(SQLITE_DONE != results) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CinemaRoomRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from cinema_rooms where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    const auto result = sqlite3_step(stmt);

    if (SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}
