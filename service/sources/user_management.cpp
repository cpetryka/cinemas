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
        UserRepository ur;
        User u {0, one_user["username"], one_user["password"], one_user["role"]};

        /*if(ur.find_pos() == -1) {
            ur.insert(u);
        }*/
    });
}
