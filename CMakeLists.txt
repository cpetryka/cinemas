cmake_minimum_required(VERSION 3.16)
project(cinemas)

set(CMAKE_CXX_STANDARD 17)

add_executable(cinemas main.cpp libs/sqlite3.h libs/sqlite3.c libs/libs.hpp connection/db_connection.cpp connection/db_connection.hpp model/cinema.hpp model/cinema_room.hpp model/seat.hpp model/movie.hpp model/seance.hpp model/user.hpp model/customer.hpp model/ticket.hpp repository/sources/cinema_repository.cpp repository/cinema_repository.hpp repository/sources/cinema_room_repository.cpp repository/cinema_room_repository.hpp)