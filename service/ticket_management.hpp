//
// Created by Cezary Petryka on 03.11.2020.
//

#ifndef CINEMAS_TICKET_MANAGEMENT_HPP
#define CINEMAS_TICKET_MANAGEMENT_HPP

#include "../repository/seance_repository.hpp"
#include "../repository/seat_repository.hpp"
#include "../repository/cinema_room_repository.hpp"
#include "../repository/ticket_repository.hpp"

class TicketManagement {
    std::vector<std::string> convert_string_to_vector(const std::string& str, const char separator) const;
    std::optional<std::unique_ptr<SeanceWithMovie>> seance_choice(const std::string& user_prefs_str) const;
    std::vector<std::unique_ptr<Seat>> find_available_places(const int seance_id, const int room_id, const int rows, const int places) const;
    int seat_choice(const int seance_id, const int cinema_room_id) const;
    std::string reservation_or_order() const;
public:
    TicketManagement() = default;

    void buy_ticket() const;
    void manage_reserved_seat(const int ticket_id) const;
};

#endif //CINEMAS_TICKET_MANAGEMENT_HPP
