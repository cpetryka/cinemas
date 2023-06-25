//
// Created by Cezary Petryka on 18.01.2021.
//

#ifndef CINEMAS_TICKET_STATUS_ANALYSER_HPP
#define CINEMAS_TICKET_STATUS_ANALYSER_HPP

#include "../libs/headers.hpp"
#include "../repository/ticket_repository.hpp"
#include "call_back_timer.hpp"

/**
 * @brief Class that is responsible for analysing tickets state.
 */
class TicketStatusAnalyser {
public:
    TicketStatusAnalyser() = default;

    /**
     * @brief Method that finds unpaid tickets and cancels them.
     */
    static void cancel_unpaid_tickets();
};

#endif //CINEMAS_TICKET_STATUS_ANALYSER_HPP
