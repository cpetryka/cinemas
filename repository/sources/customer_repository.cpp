//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../customer_repository.hpp"

void CustomerRepository::insert(const Customer &customer) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into customers(name, surname, age, gender, city, user_id) values (?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, customer.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, customer.surname.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, customer.age);
    sqlite3_bind_text(stmt, 4, customer.gender.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, customer.city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, customer.user_id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CustomerRepository::update(const int id, const Customer &customer) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update customers set name = ?, surname = ?, age = ?, gender = ?, city = ?, user_id = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, customer.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, customer.surname.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, customer.age);
    sqlite3_bind_text(stmt, 4, customer.gender.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, customer.city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, customer.user_id);
    sqlite3_bind_int(stmt, 7, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void CustomerRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from customers where id = ?";
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
