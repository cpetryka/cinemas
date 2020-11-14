//
// Created by Cezary Petryka on 03.11.2020.
//

#ifndef CINEMAS_TICKET_MANAGEMENT_HPP
#define CINEMAS_TICKET_MANAGEMENT_HPP

#include "../repository/seance_repository.hpp"

class TicketManagement {
    std::vector<std::string> convert_string_to_vector(const std::string& str, const char separator) const;
    int seance_choice(const std::string& user_prefs_str) const;
public:
    TicketManagement() = default;

    void buy_ticket() const;
};


#endif //CINEMAS_TICKET_MANAGEMENT_HPP
