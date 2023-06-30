//
// Created by Cezary Petryka on 27.10.2020.
//

#include "../user_service.hpp"

void UserService::change_password(const int customer_id) {
    std::cout << "Enter new password: " << std::endl;
    std::string new_password;
    std::getline(std::cin, new_password);
    system("cls");

    auto customer = CustomerRepository::find_by_id(customer_id).value();

    auto user = UserRepository::find_by_id(customer->user_id).value();
    UserRepository::update(user->id, User{user->id, user->username, new_password, user->role});
}

UserService::UserService(const std::string &file_name) {
    add_users_to_the_database(file_name);
}

void UserService::add_users_to_the_database(const std::string &file_name) const {
    json data = Utils::get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_user) {
        std::string user_role_tmp = one_user["role"];
        User u {0, one_user["username"], one_user["password"], user_role_tmp};

        // If there is no such user, this adds it
        if(!UserRepository::find_pos(u).has_value()) {
            UserRepository::insert(u);
        }

        if(UserRole::to_string(u.role) == "CUSTOMER") {
            auto user_id = UserRepository::find_pos(u).value();
            std::string gender_tmp = one_user["gender"];
            Customer c{0, one_user["name"], one_user["surname"], one_user["age"], gender_tmp, one_user["city"], user_id};

            if(!CustomerRepository::find_pos(c).has_value()) {
                CustomerRepository::insert(c);
            }
        }
    });
}

int UserService::sign_in() {
    auto counter = 0;
    std::string username, password;
    std::optional<int> found_customer;

    do {
        std::cout << "Enter your username:" << std::endl;
        std::getline(std::cin, username);

        std::cout << "Enter your password:" << std::endl;
        std::getline(std::cin, password);

        found_customer = CustomerRepository::find_customer_by_username_and_password(username, password);
        system("cls");
    } while(++counter < 3 && !found_customer.has_value());

    if(!found_customer.has_value()) {
        throw NoSuchUserException{"There is no user with a given login or password."};
    }

    return found_customer.value();
}

void UserService::manage_account() {
    auto customer_id = sign_in();
    auto user_choice = 0;

    while(true) {
        std::cout << "================ ACCOUNT MENU ================" << std::endl;
        std::cout << "== 1. CHANGE PASSWORD" << std::endl;
        std::cout << "== 9. EXIT" << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << "Your choice: " << std::endl;
        std::cin >> user_choice; std::cin.get();
        system("cls");

        switch (user_choice) {
            case 1:
                change_password(customer_id);
                break;
            case 9:
                return;
            default:
                std::cout << "There is no such option! Try again." << std::endl;
        }
    }
}