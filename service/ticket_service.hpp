//
// Created by Cezary Petryka on 03.11.2020.
//

#ifndef CINEMAS_TICKET_SERVICE_HPP
#define CINEMAS_TICKET_SERVICE_HPP

#include "../utils/utils.hpp"
#include "../repository/seance_repository.hpp"
#include "../repository/seat_repository.hpp"
#include "../repository/cinema_room_repository.hpp"
#include "../repository/ticket_repository.hpp"
#include "user_service.hpp"

/**
 * @brief Class that is responsible for managing tickets.
 */
class TicketService {
    /**
     * @brief Method that allows to get user preferences.
     * @return std::string representing user preferences.
     */
    std::string get_user_preferences() const;

    /**
     * @brief Method that allows to get available seances.
     * @param std::vector<std::unique_ptr<SeanceWithMovie>> representing available seances.
     * @return std::string representing available seances.
     */
    std::string generate_available_seance_info(const std::vector<std::unique_ptr<SeanceWithMovie>>& available_seances) const;

    /**
     * @brief Method that allows to get selected seance.
     * @param int representing seance number.
     * @return int representing selected seance.
     */
    int get_selected_seance(const int seance_number) const;

    /**
     * @brief Method that allows to choose seance.
     * @param std::string representing user preferences.
     * @return std::optional<std::unique_ptr<SeanceWithMovie>> representing chosen seance.
     */
    std::optional<std::unique_ptr<SeanceWithMovie>> seance_choice(const std::string& user_prefs_str) const;

    /**
     * @brief Method that allows to get available places.
     * @param int representing seance id.
     * @param int representing cinema room id.
     * @param int representing number of rows.
     * @param int representing number of places.
     * @return std::vector<std::unique_ptr<Seat>> representing available places.
     */
    std::vector<std::unique_ptr<Seat>> find_available_places(const int seance_id, const int room_id, const int rows, const int places) const;

    /**
     * @brief Method that allows to check if places are available and convert them.
     * @param std::vector<int> representing chosen places.
     * @param std::vector<std::unique_ptr<Seat>> representing available places.
     * @return bool representing if places are available and converted.
     */
    bool check_if_places_are_available_and_conversion(std::vector<int>& chosen_places, const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) const;

    /**
     * @brief Method that allows to get available places.
     * @param std::vector<std::unique_ptr<Seat>> representing available places.
     * @param int representing number of places.
     * @return std::string representing available places.
     */
    std::string generate_available_places_info(const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room, const int places) const;

    /**
     * @brief Method that allows to get selected places.
     * @param std::vector<std::unique_ptr<Seat>> representing available places.
     * @return std::vector<int> representing selected places.
     */
    std::vector<int> get_selected_places(const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) const;

    /**
     * @brief Method that allows to choose places.
     * @param int representing seance id.
     * @param int representing cinema room id.
     * @return std::vector<int> representing chosen places.
     */
    std::vector<int> seat_choice(const int seance_id, const int cinema_room_id) const;

    /**
     * @brief Method that allows to choose reservation or order.
     */
    std::string reservation_or_order() const;
public:
    TicketService() = default;

    /**
     * @brief Method that allows to buy a ticket.
     */
    void buy_ticket() const;

    /**
     * @brief Method that allows to manage the ticket.
     */
    static void manage_ticket(const int ticket_id);
};

#endif //CINEMAS_TICKET_SERVICE_HPP
