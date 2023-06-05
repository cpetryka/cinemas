//
// Created by Cezary Petryka on 18.01.2021.
//

#ifndef CINEMAS_TICKET_STATUS_ANALYSIS_HPP
#define CINEMAS_TICKET_STATUS_ANALYSIS_HPP

#include "../libs/headers.hpp"
#include "../repository/ticket_repository.hpp"
#include "../helpers/call_back_timer.hpp"

/**
 * @brief Class that is responsible for analysing tickets state.
 */
class TicketStatusAnalysis {
public:
    TicketStatusAnalysis() = default;

    /**
     * @brief Method that allows to analyse tickets state.
     */
    static void analyse_tickets_state();
    // void repetitive_ticket_state_analysis();
};

#endif //CINEMAS_TICKET_STATUS_ANALYSIS_HPP
