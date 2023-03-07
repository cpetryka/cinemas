//
// Created by Cezary Petryka on 03.11.2020.
//

#ifndef CINEMAS_TICKET_MANAGER_HPP
#define CINEMAS_TICKET_MANAGER_HPP

#include "../repository/seance_repository.hpp"
#include "../repository/seat_repository.hpp"
#include "../repository/cinema_room_repository.hpp"
#include "../repository/ticket_repository.hpp"
#include "user_manager.hpp"

class TicketManager {
    std::string get_user_preferences() const;
    std::vector<std::string> convert_string_to_vector(const std::string& str, const char separator) const;
    std::string generate_available_seance_info(const std::vector<std::unique_ptr<SeanceWithMovie>>& available_seances) const;
    int get_selected_seance(const int seance_number) const;
    std::optional<std::unique_ptr<SeanceWithMovie>> seance_choice(const std::string& user_prefs_str) const;
    std::vector<std::unique_ptr<Seat>> find_available_places(const int seance_id, const int room_id, const int rows, const int places) const;
    bool check_if_places_are_available_and_conversion(std::vector<int>& chosen_places, const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) const;
    std::string generate_available_places_info(const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room, const int places) const;
    std::vector<int> get_selected_places(const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) const;
    std::vector<int> seat_choice(const int seance_id, const int cinema_room_id) const;
    std::string reservation_or_order() const;
public:
    TicketManager() = default;

    void buy_ticket() const;
    void manage_reserved_seat(const int ticket_id) const;
};

#endif //CINEMAS_TICKET_MANAGER_HPP
