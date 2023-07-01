//
// Created by Cezary Petryka on 18.01.2021.
//

#include "../ticket_status_analyser.hpp"

void TicketStatusAnalyser::cancel_unpaid_tickets() {
    auto tickets_to_cancel = TicketRepository::find_reservations_to_cancel();

    std::ranges::for_each(tickets_to_cancel, [](const int idx) {
        TicketRepository::cancel_ticket_by_id(idx);
    });
}