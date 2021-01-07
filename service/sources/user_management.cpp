//
// Created by Cezary Petryka on 27.10.2020.
//

#include "../user_management.hpp"

json UserManagement::get_data_from_json_file(const std::string &file_name) const {
    std::ifstream reading(file_name);
    json j;

    if(reading.is_open()) {
        reading >> j;
        reading.close();
    }
    else {
        throw std::runtime_error{"the file '" + file_name + "' could not be opened"};
    }

    return j;
}

UserManagement::UserManagement(const std::string &file_name) {
    get_users_to_the_database(file_name);
}

void UserManagement::get_users_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_user) {
        User u {0, one_user["username"], one_user["password"], one_user["role"]};

        // If there is no such user, this adds it
        if(!UserRepository::find_pos(u).has_value()) {
            UserRepository ur;
            ur.insert(u);
        }

        if(u.role == "CUSTOMER") {
            CustomerRepository cr;
            auto user_id = UserRepository::find_pos(u).value();
            Customer c{0, one_user["name"], one_user["surname"], one_user["age"], one_user["gender"], one_user["city"], user_id};

            if(!CustomerRepository::find_pos(c).has_value()) {
                cr.insert(c);
            }
        }
    });
}

int UserManagement::sign_in() {
    auto counter = 0;
    std::string username, password;
    std::optional<int> found_customer;

    do {
        std::cout << "Enter your username:" << std::endl;
        std::getline(std::cin, username);

        std::cout << "Enter your password:" << std::endl;
        std::getline(std::cin, password);

        found_customer = CustomerRepository::find_customer_by_username_and_password(username, password);
    } while(++counter < 3 && !found_customer.has_value());

    if(!found_customer.has_value()) {
        throw std::runtime_error{"There is no user with a given login or password."};
    }

    return found_customer.value();
}
