//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CUSTOMER_HPP
#define CINEMAS_CUSTOMER_HPP

#include "../libs/libs.hpp"

struct Customer {
    int id;
    std::string name;
    std::string surname;
    int age;
    std::string gender;
    std::string city;
    int user_id;
};

#endif //CINEMAS_CUSTOMER_HPP
