//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_TICKET_HPP
#define CINEMAS_TICKET_HPP

#include "../libs/headers.hpp"
#include "../enums/ticket_state.hpp"

/**
 * @brief Class that represents ticket.
 */
struct Ticket {
    int id;
    int customer_id;
    int seance_id;
    int seat_id;
    int price;
    ticket_state state;

    Ticket(const int id, const int customer_id, const int seance_id, const int seat_id, const int price,
           const std::string& state) : id{id}, customer_id{customer_id}, seance_id{seance_id}, seat_id{seat_id},
           price{price}, state{TicketState::from_string(state)} {}

    friend std::ostream& operator<<(std::ostream& out, const Ticket& ticket) {
        out << "TICKET ID: " << ticket.id << ", CUSTOMER ID: " << ticket.customer_id << ", SEANCE ID: " << ticket.seance_id
            << ", SEAT ID: " << ticket.seat_id << ", PRICE: " << ticket.price << ", STATE: " << TicketState::to_string(ticket.state);

        return out;
    }
};

#endif //CINEMAS_TICKET_HPP
