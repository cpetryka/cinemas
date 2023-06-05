//
// Created by Cezary Petryka on 27.10.2020.
//

#ifndef CINEMAS_USER_MANAGER_HPP
#define CINEMAS_USER_MANAGER_HPP

#include "../repository/user_repository.hpp"
#include "../repository/customer_repository.hpp"

/**
 * @brief Class that is responsible for managing users.
 */
class UserManager {
    /**
     * @brief Method that allows to get data from json file.
     * @param std::string representing file name.
     * @return json object.
     */
    json get_data_from_json_file(const std::string &file_name) const;

    /**
     * @brief Method that allows to change customer's password.
     */
    static void change_password(const int customer_id);
public:
    explicit UserManager() = default;
    explicit UserManager(const std::string& file_name);

    /**
     * @brief Method that allows to add users to the database.
     * @param std::string representing file name.
     */
    void get_users_to_the_database(const std::string& file_name) const;

    /**
     * @brief Method that allows to sign in.
     * @return int representing customer's id.
     */
    static int sign_in();

    /**
     * @brief Method that allows to manage account.
     */
    static void account_management();
};


#endif //CINEMAS_USER_MANAGER_HPP
