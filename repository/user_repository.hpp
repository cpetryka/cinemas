//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_USER_REPOSITORY_HPP
#define CINEMAS_USER_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/user.hpp"
#include "../connection/db_connection.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'user' table.
 */
class UserRepository {
public:
    /**
     * @brief Method that allows to insert new user to database.
     * @param User object to insert.
     */
    void insert(const User& user);

    /**
     * @brief Methods that allows to update a user at a given id.
     * @param int id of user to update.
     * @param User object to update.
     */
    void update(const int id, const User& user);

    /**
     * @brief Method that allows to remove a user at a given id.
     * @param int id of user to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a position of user in database.
     * @param User object to find.
     * @return std::optional<int> position of user in database.
     */
    static std::optional<int> find_pos(const User& user);

    /**
     * @brief Method that allows to find a user by id.
     * @param int id of user to find.
     * @return std::optional<std::unique_ptr<User>> user object wrapped by std::optional.
     */
    std::optional<std::unique_ptr<User>> find_by_id(const int idx);
};


#endif //CINEMAS_USER_REPOSITORY_HPP
