//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_TICKET_REPOSITORY_HPP
#define CINEMAS_TICKET_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/ticket.hpp"
#include "../connection/db_connection.hpp"

class TicketRepository {
public:
    void insert(const Ticket& ticket);
    void update(const int id, const Ticket& ticket);
    void remove(const int id);
};


#endif //CINEMAS_TICKET_REPOSITORY_HPP
