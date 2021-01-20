//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CUSTOMER_HPP
#define CINEMAS_CUSTOMER_HPP

#include "../libs/libs.hpp"
#include "../enums/customer_gender.hpp"

struct Customer {
    int id;
    std::string name;
    std::string surname;
    int age;
    // std::string gender;
    customer_gender gender;
    std::string city;
    int user_id;

    Customer(const int id, const std::string& name, const std::string& surname, const int age, const std::string& gender, const std::string& city, const int user_id)
        : id{id}, name{name}, surname{surname}, age{age}, gender{CustomerGender::from_string(gender)},
          city{city}, user_id{user_id} {}

    Customer(const int id, const std::string& name, const std::string& surname, const int age, const customer_gender& gender, const std::string& city, const int user_id)
            : id{id}, name{name}, surname{surname}, age{age}, gender{gender}, city{city}, user_id{user_id} {}
};

#endif //CINEMAS_CUSTOMER_HPP
