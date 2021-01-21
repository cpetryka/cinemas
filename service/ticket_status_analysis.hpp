//
// Created by Cezary Petryka on 18.01.2021.
//

#ifndef CINEMAS_TICKET_STATUS_ANALYSIS_HPP
#define CINEMAS_TICKET_STATUS_ANALYSIS_HPP

#include "../libs/libs.hpp"
#include "../repository/ticket_repository.hpp"
#include "../useful/call_back_timer.hpp"

class TicketStatusAnalysis {
    void analyse_tickets_state();
    void repetitive_ticket_state_analysis();
public:
    TicketStatusAnalysis();
};

#endif //CINEMAS_TICKET_STATUS_ANALYSIS_HPP
