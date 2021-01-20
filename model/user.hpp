//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_USER_HPP
#define CINEMAS_USER_HPP

#include "../libs/libs.hpp"
#include "../enums/user_role.hpp"

struct User {
    int id;
    std::string username;
    std::string password;
    // std::string role;
    user_role role;

    User(const int id, const std::string& username, const std::string& password, const std::string& role)
        : id{id}, username{username}, password{password}, role{UserRole::from_string(role)} {}

    User(const int id, const std::string& username, const std::string& password, const user_role& role)
            : id{id}, username{username}, password{password}, role{role} {}
};

#endif //CINEMAS_USER_HPP
