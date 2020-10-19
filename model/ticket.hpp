//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_TICKET_HPP
#define CINEMAS_TICKET_HPP

#include "../libs/libs.hpp"

struct Ticket {
    int id;
    int customer_id;
    int seance_id;
    int seat_id;
    int price;
    std::string state;
};

#endif //CINEMAS_TICKET_HPP
