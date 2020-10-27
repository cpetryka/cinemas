//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_CUSTOMER_REPOSITORY_HPP
#define CINEMAS_CUSTOMER_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/customer.hpp"
#include "../connection/db_connection.hpp"

class CustomerRepository {
public:
    void insert(const Customer& customer);
    void update(const int id, const Customer& customer);
    void remove(const int id);
    int find_pos(const Customer& customer);
};


#endif //CINEMAS_CUSTOMER_REPOSITORY_HPP
