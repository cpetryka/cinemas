//
// Created by Cezary Petryka on 27.10.2020.
//

#ifndef CINEMAS_USER_MANAGEMENT_HPP
#define CINEMAS_USER_MANAGEMENT_HPP

#include "../repository/user_repository.hpp"
#include "../repository/customer_repository.hpp"

class UserManagement {
    json get_data_from_json_file(const std::string &file_name) const;
public:
    explicit UserManagement() = default;
    explicit UserManagement(const std::string& file_name);

    void get_users_to_the_database(const std::string& file_name) const;
};


#endif //CINEMAS_USER_MANAGEMENT_HPP
