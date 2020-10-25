//
// Created by Cezary Petryka on 19.10.2020.
//

#include "../cinema_repository.hpp"

void CinemaRepository::insert(const Cinema &cinema) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into cinemas(name, city) values (?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, cinema.city.c_str(), -1, SQLITE_STATIC);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CinemaRepository::update(const int id, const Cinema &cinema) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update cinemas set name = ?, city = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, cinema.city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, id);
    const auto results = sqlite3_step(stmt);

    if(SQLITE_DONE != results) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CinemaRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from cinemas where id = ?";
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

int CinemaRepository::find_pos(const Cinema &cinema) {
    const std::string sql = "select id from cinemas where name = ? and city = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, cinema.name.c_str(), -1, 0);
    sqlite3_bind_text(stmt, 2, cinema.city.c_str(), -1, 0);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return -1;
}
