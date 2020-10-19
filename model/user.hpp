//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_USER_HPP
#define CINEMAS_USER_HPP

#include "../libs/libs.hpp"

struct User {
    int id;
    std::string username;
    std::string password;
    std::string role;
};

#endif //CINEMAS_USER_HPP
