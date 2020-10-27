//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../seance_repository.hpp"

void SeanceRepository::insert(const Seance &seance) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into seances(movie_id, cinema_room_id, date_time) values (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, SQLITE_STATIC);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void SeanceRepository::update(const int id, const Seance &seance) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update seances set movie_id = ?, cinema_room_id = ?, date_time = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void SeanceRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from seances where id = ?";
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

int SeanceRepository::find_pos(const Seance &seance) {
    const std::string sql = "select id from seances where movie_id = ? and cinema_room_id = ? and date_time = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, 0);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return -1;
}
