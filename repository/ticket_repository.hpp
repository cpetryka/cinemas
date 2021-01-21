//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_TICKET_REPOSITORY_HPP
#define CINEMAS_TICKET_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/ticket.hpp"
#include "../connection/db_connection.hpp"
#include "../model/date_time.hpp"

class TicketRepository {
    static std::string from_unsigned_char_to_std_string(const unsigned char* value);
public:
    void insert(const Ticket& ticket);
    void update(const int id, const Ticket& ticket);
    void remove(const int id);
    static std::vector<int> find_reserved_seats(const int seance_id);
    static std::optional<std::unique_ptr<Ticket>> find_by_id(const int idx);
    static std::vector<int> find_reservations_to_cancel();
};


#endif //CINEMAS_TICKET_REPOSITORY_HPP
