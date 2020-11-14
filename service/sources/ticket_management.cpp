//
// Created by Cezary Petryka on 03.11.2020.
//

#include "../ticket_management.hpp"

std::vector<std::string> TicketManagement::convert_string_to_vector(const std::string& str, const char separator) const {
    std::vector<std::string> strings;
    std::string one_string;
    std::stringstream ss(str);

    while(getline(ss, one_string, separator)) {
        strings.emplace_back(one_string);
    }

    return strings;
}


int TicketManagement::seance_choice(const std::string& user_prefs_str) const {
    auto user_prefs = convert_string_to_vector(user_prefs_str, ',');
    auto available_seances = SeanceRepository::find_by_parameters(user_prefs.at(0), user_prefs.at(1), user_prefs.at(2), user_prefs.at(3));
    auto user_choice = 0;

    if(available_seances.size() == 0) {
        return -1;
    }

    for(auto i = 0; i < available_seances.size(); ++i) {
        std::cout << i << " -> " << *available_seances.at(i) << std::endl;
    }

    do {
        std::cout << "Which seance do you choose?: ";
        std::cin >> user_choice; std::cin.get();
    } while(user_choice < 0 || user_choice > available_seances.size() - 1);

    return available_seances.at(user_choice)->seance_id;
}

void TicketManagement::buy_ticket() const {
    std::cout << "Specify your preferences (movie_genre, city, date, time): " << std::endl;
    std::string user_preferences;
    std::getline(std::cin, user_preferences);

    auto index_of_chosen_seance = seance_choice(user_preferences);
}