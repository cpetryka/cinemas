//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_USER_REPOSITORY_HPP
#define CINEMAS_USER_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../model/user.hpp"
#include "../connection/db_connection.hpp"

class UserRepository {
    std::string from_unsigned_char_to_std_string(const unsigned char *value);
public:
    void insert(const User& user);
    void update(const int id, const User& user);
    void remove(const int id);
    static std::optional<int> find_pos(const User& user);
    std::optional<std::unique_ptr<User>> find_by_id(const int idx);
};


#endif //CINEMAS_USER_REPOSITORY_HPP
