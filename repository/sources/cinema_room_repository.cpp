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

std::optional<int> CinemaRoomRepository::find_pos_by_name(const std::string &name) {
    const std::string sql = "select id from cinema_rooms where name = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, 0);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}


std::optional<int> CinemaRoomRepository::find_pos(const CinemaRoom &cinema_room) {
    const std::string sql = "select id from cinema_rooms where name = ? and cinema_id = ? and rows = ? and places = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema_room.name.c_str(), -1, 0);
    sqlite3_bind_int(stmt, 2, cinema_room.cinema_id);
    sqlite3_bind_int(stmt, 3, cinema_room.rows);
    sqlite3_bind_int(stmt, 4, cinema_room.places);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}


std::optional<std::unique_ptr<CinemaRoom>> CinemaRoomRepository::find_by_id(const int idx) {
    const std::string sql = "select id, name, cinema_id, rows, places from cinema_rooms where id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<CinemaRoom>(CinemaRoom{
                sqlite3_column_int(stmt, 0),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 1)),
                sqlite3_column_int(stmt, 2),
                sqlite3_column_int(stmt, 3),
                sqlite3_column_int(stmt, 4)
        }));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::vector<std::unique_ptr<Seat>>
CinemaRoomRepository::find_all_seats_in_given_room(const int room_id, const int rows, const int places) {
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room;

    for(auto i = 0; i < rows; ++i) {
        for(auto j = 0; j < places; ++j) {
            seats_in_cinema_room.emplace_back(std::make_unique<Seat>(*SeatRepository::find_by_parameters(room_id, i + 1, j + 1).value()));
        }
    }

    return seats_in_cinema_room;
}