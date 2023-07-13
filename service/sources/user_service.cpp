//
// Created by Cezary Petryka on 27.10.2020.
//

#include "../user_service.hpp"

std::optional<int> UserService::sign_in() {
    auto counter {0};
    auto username = std::string{};
    auto password = std::string{};
    auto customer_id = std::optional<int>{};

    do {
        std::cout << "Enter your username:" << std::endl;
        std::getline(std::cin, username);

        std::cout << "Enter your password:" << std::endl;
        std::getline(std::cin, password);

        customer_id = CustomerRepository::find_customer_by_username_and_password(username, password);

        if(!customer_id.has_value() && counter < 2) {
            std::cout << "You have entered wrong username or password. Try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        if(!customer_id.has_value() && counter == 2) {
            std::cout << "You have entered wrong username or password 3 times. Try again later." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        system("cls");
    } while(++counter < 3 && !customer_id.has_value());

    return customer_id;
}

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
    json users_data = Utils::get_data_from_json_file(file_name);

    std::ranges::for_each(users_data, [](const auto& user_data) {
        std::string user_role_tmp = user_data["role"];
        User u {0, user_data["username"], user_data["password"], user_role_tmp};

        // If there is no such user, this adds it
        if(!UserRepository::find_pos(u).has_value()) {
            UserRepository::insert(u);
        }

        // If the user is a customer, this adds it
        if(UserRole::to_string(u.role) == "CUSTOMER") {
            auto user_id = UserRepository::find_pos(u).value();
            std::string gender_tmp = user_data["gender"];
            Customer c{0, user_data["name"], user_data["surname"], user_data["age"], gender_tmp, user_data["city"], user_id};

            if(!CustomerRepository::find_pos(c).has_value()) {
                CustomerRepository::insert(c);
            }
        }
    });
}

void UserService::manage_account() {
    auto customer_id = sign_in();

    if(!customer_id.has_value()) {
        return;
    }

    while(true) {
        std::cout << "================ ACCOUNT MENU ================" << std::endl;
        std::cout << "== 1. CHANGE PASSWORD                       ==" << std::endl;
        std::cout << "== 2. SHOW YOUR TICKETS                     ==" << std::endl;
        std::cout << "== 9. RETURN TO THE MAIN MENU               ==" << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << std::endl << "Your choice: " << std::endl;
        auto user_choice = 0;
        std::cin >> user_choice; std::cin.get();
        system("cls");

        switch (user_choice) {
            case 1:
                change_password(customer_id.value());
                break;
            case 2:
                {
                    auto tickets = TicketRepository::find_all_by_customer_id(customer_id.value());

                    std::cout << "================ YOUR TICKETS ================" << std::endl;

                    if(tickets.empty()) {
                        std::cout << "You have not bought any tickets yet." << std::endl;
                    }
                    else {
                        std::ranges::for_each(tickets, [](const auto& ticket) {
                            std::cout << *ticket << std::endl;
                        });
                    }
                }
                break;
            case 9:
                return;
            default:
                std::cout << "There is no such option! Try again." << std::endl;
        }
    }
}