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
    std::string customer_gender_tmp = CustomerGender::to_string(customer.gender);
    sqlite3_bind_text(stmt, 4, customer_gender_tmp.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, customer.city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, customer.user_id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
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
    std::string customer_gender_tmp = CustomerGender::to_string(customer.gender);
    sqlite3_bind_text(stmt, 4, customer_gender_tmp.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, customer.city.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, customer.user_id);
    sqlite3_bind_int(stmt, 7, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
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
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}


std::optional<std::unique_ptr<Customer>> CustomerRepository::find_by_id(const int idx) {
    const std::string sql = "select name, surname, age, gender, city, user_id from customers where id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idx);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(std::make_unique<Customer>(Customer{
            idx,
            Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 0)),
            Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 1)),
            sqlite3_column_int(stmt, 2),
            Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 3)),
            Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 4)),
            sqlite3_column_int(stmt, 5)

        }));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}


std::optional<int> CustomerRepository::find_pos(const Customer &customer) {
    const std::string sql = "select id from customers where name = ? and surname = ? and age = ? and gender = ? and city = ? and user_id = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, customer.name.c_str(), -1, 0);
    sqlite3_bind_text(stmt, 2, customer.surname.c_str(), -1, 0);
    sqlite3_bind_int(stmt, 3, customer.age);
    std::string customer_gender_tmp = CustomerGender::to_string(customer.gender);
    sqlite3_bind_text(stmt, 4, customer_gender_tmp.c_str(), -1, 0);
    sqlite3_bind_text(stmt, 5, customer.city.c_str(), -1, 0);
    sqlite3_bind_int(stmt, 6, customer.user_id);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::optional<int> CustomerRepository::find_customer_by_username_and_password(const std::string &username, const std::string &password) {
    const std::string sql = "select c.id from customers c join users u on c.user_id = u.id where u.username = ? and u.password = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, 0);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, 0);

    auto result = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}