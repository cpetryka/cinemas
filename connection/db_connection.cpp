//
// Created by Cezary Petryka on 12.10.2020.
//

#include "db_connection.hpp"

DbConnection::DbConnection() {
    if (SQLITE_OK != sqlite3_open(DATABASE_NAME.c_str(), &connection))
    {
        throw std::runtime_error{ sqlite3_errmsg(connection) };
    }

    create_tables();
}

void DbConnection::create_tables() const {
    const std::string sql_cinema = "create table if not exists cinemas (id integer primary key autoincrement, name varchar(50) not null, city varchar(50) not null);";
    char** error_message1 = nullptr;
    const auto result1 = sqlite3_exec(connection, sql_cinema.c_str(), nullptr, nullptr, error_message1);
    if(result1 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message1);
        throw std::runtime_error{ "cinemas table creation exception" };
    }

    const std::string sql_cinema_room = "create table if not exists cinema_rooms (id integer primary key autoincrement, name varchar(50) not null, cinema_id integer, rows integer default 0, places integer default 0, foreign key (cinema_id) references cinemas (id) on delete cascade on update cascade);";
    char** error_message2 = nullptr;
    const auto result2 = sqlite3_exec(connection, sql_cinema_room.c_str(), nullptr, nullptr, error_message2);
    if(result2 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message2);
        throw std::runtime_error{ "cinema_rooms table creation exception" };
    }

    const std::string sql_seat = "create table if not exists seats (id integer primary key autoincrement, cinema_room_id integer, row integer, place integer, foreign key (cinema_room_id) references cinema_rooms (id) on delete cascade on update cascade);";
    char** error_message3 = nullptr;
    const auto result3 = sqlite3_exec(connection, sql_seat.c_str(), nullptr, nullptr, error_message3);
    if(result3 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message3);
        throw std::runtime_error{ "seats table creation exception" };
    }

    const std::string sql_movie = "create table if not exists movies (id integer primary key autoincrement, title varchar(50) not null, genre varchar(50) not null, author varchar(50) not null);";
    char** error_message4 = nullptr;
    const auto result4 = sqlite3_exec(connection, sql_movie.c_str(), nullptr, nullptr, error_message4);
    if(result4 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message4);
        throw std::runtime_error{ "movies table creation exception" };
    }

    const std::string sql_seance = "create table if not exists seances (id integer primary key autoincrement, movie_id integer, cinema_room_id integer, date_time varchar(50) not null, foreign key (movie_id) references movies (id) on delete cascade on update cascade, foreign key (cinema_room_id) references cinema_rooms (id) on delete cascade on update cascade);";
    char** error_message5 = nullptr;
    const auto result5 = sqlite3_exec(connection, sql_seance.c_str(), nullptr, nullptr, error_message5);
    if(result5 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message5);
        throw std::runtime_error{ "seances table creation exception" };
    }

    const std::string sql_user = "create table if not exists users (id integer primary key autoincrement, username varchar(50) not null, password varchar(50) not null, role varchar(50) not null);";
    char** error_message6 = nullptr;
    const auto result6 = sqlite3_exec(connection, sql_user.c_str(), nullptr, nullptr, error_message6);
    if(result6 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message6);
        throw std::runtime_error{ "users table creation exception" };
    }

    const std::string sql_customer = "create table if not exists customers (id integer primary key autoincrement, name varchar(50) not null, surname varchar(50) not null, age integer, gender varchar(50) not null, city varchar(50) not null, user_id integer, foreign key (user_id) references users (id) on delete cascade on update cascade);";
    char** error_message7 = nullptr;
    const auto result7 = sqlite3_exec(connection, sql_customer.c_str(), nullptr, nullptr, error_message7);
    if(result7 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message7);
        throw std::runtime_error{ "customers table creation exception" };
    }

    const std::string sql_ticket = "create table if not exists tickets (id integer primary key autoincrement, customer_id integer, seance_id integer, seat_id integer, price integer, state varchar(50) not null, foreign key (customer_id) references customers (id) on delete cascade on update cascade, foreign key (seance_id) references seances (id) on delete cascade on update cascade, foreign key (seat_id) references seats (id) on delete cascade on update cascade);";
    char** error_message8 = nullptr;
    const auto result8 = sqlite3_exec(connection, sql_ticket.c_str(), nullptr, nullptr, error_message8);
    if(result8 != SQLITE_OK) {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_free(error_message8);
        throw std::runtime_error{ "tickets table creation exception" };
    }
}

DbConnection* DbConnection::get_instance()
{
    return instance;
}

sqlite3* DbConnection::get_connection() const
{
    return connection;
}

DbConnection* DbConnection::instance = new DbConnection{};