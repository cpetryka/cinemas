//
// Created by Cezary Petryka on 27.10.2020.
//

#ifndef CINEMAS_USER_MANAGER_HPP
#define CINEMAS_USER_MANAGER_HPP

#include "../repository/user_repository.hpp"
#include "../repository/customer_repository.hpp"

class UserManager {
    json get_data_from_json_file(const std::string &file_name) const;
    static void change_password(const int customer_id);
public:
    explicit UserManager() = default;
    explicit UserManager(const std::string& file_name);

    void get_users_to_the_database(const std::string& file_name) const;
    static int sign_in();
    static void account_management();
};


#endif //CINEMAS_USER_MANAGER_HPP
