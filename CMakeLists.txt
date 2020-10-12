cmake_minimum_required(VERSION 3.16)
project(cinemas)

set(CMAKE_CXX_STANDARD 17)

add_executable(cinemas main.cpp libs/sqlite3.h libs/sqlite3.c libs/libs.hpp connection/db_connection.cpp connection/db_connection.hpp)