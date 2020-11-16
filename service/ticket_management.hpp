//
// Created by Cezary Petryka on 03.11.2020.
//

#ifndef CINEMAS_TICKET_MANAGEMENT_HPP
#define CINEMAS_TICKET_MANAGEMENT_HPP

#include "../repository/seance_repository.hpp"
#include "../repository/seat_repository.hpp"
#include "../repository/cinema_room_repository.hpp"

class TicketManagement {
    std::vector<std::string> convert_string_to_vector(const std::string& str, const char separator) const;
    std::optional<std::unique_ptr<SeanceWithMovie>> seance_choice(const std::string& user_prefs_str) const;
    // std::vector<std::vector<int>> check_which_places_are_available();
    int seat_choice(const int cinema_room_id) const;
public:
    TicketManagement() = default;

    void buy_ticket() const;
};


#endif //CINEMAS_TICKET_MANAGEMENT_HPP
