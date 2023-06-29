//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_CUSTOMER_REPOSITORY_HPP
#define CINEMAS_CUSTOMER_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/customer.hpp"
#include "../connection/db_connection.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'customer' table.
 */
class CustomerRepository {
public:
    /**
     * @brief Method that allows to insert new customer to database.
     * @param Customer object to insert.
     */
    void insert(const Customer& customer);

    /**
     * @brief Methods that allows to update a customer at a given id.
     * @param int id of customer to update.
     * @param Customer object to update.
     */
    void update(const int id, const Customer& customer);

    /**
     * @brief Method that allows to remove a customer at a given id.
     * @param int id of customer to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a customer by id.
     * @param int id of customer to find.
     * @return std::optional<std::unique_ptr<Customer>> customer object wrapped by std::optional.
     */
    std::optional<std::unique_ptr<Customer>> find_by_id(const int idx);

    /**
     * @brief Method that allows to find a position of customer in database.
     * @param Customer object to find.
     * @return std::optional<int> position of customer in database.
     */
    static std::optional<int> find_pos(const Customer& customer);

    /**
     * @brief Method that allows to find a position of customer by their username and password in database.
     * @param std::string username of customer to find.
     * @return std::optional<int> position of customer in database.
     */
    static std::optional<int> find_customer_by_username_and_password(const std::string& username, const std::string& password);
};

#endif //CINEMAS_CUSTOMER_REPOSITORY_HPP
