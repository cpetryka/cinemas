//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_USER_REPOSITORY_HPP
#define CINEMAS_USER_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/user.hpp"
#include "../connection/db_connection.hpp"

class UserRepository {
public:
    void insert(const User& user);
    void update(const int id, const User& user);
    void remove(const int id);
};


#endif //CINEMAS_USER_REPOSITORY_HPP
