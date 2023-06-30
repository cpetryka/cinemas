//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../user_repository.hpp"

void UserRepository::insert(const User& user) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into users(username, password, role) values (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, user.username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user.password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, UserRole::to_string(user.role).c_str(), -1, SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void UserRepository::update(const int id, const User &user) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update users set username = ?, password = ?, role = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, user.username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user.password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, UserRole::to_string(user.role).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void UserRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from users where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

std::optional<int> UserRepository::find_pos(const User &user) {
    const std::string sql = "select id from users where username = ? and password = ? and role = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, user.username.c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, user.password.c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 3, UserRole::to_string(user.role).c_str(), -1, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::optional<std::unique_ptr<User>> UserRepository::find_by_id(const int idx) {
    const std::string sql = "select username, password, role from users where id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<User>(
                idx,
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 0)),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 1)),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 2))
        ));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}
