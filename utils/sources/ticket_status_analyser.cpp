//
// Created by Cezary Petryka on 18.01.2021.
//

#include "../ticket_status_analyser.hpp"

void TicketStatusAnalyser::cancel_unpaid_tickets() {
    TicketRepository tr;
    auto tickets_to_cancel = tr.find_reservations_to_cancel();

    std::for_each(tickets_to_cancel.begin(), tickets_to_cancel.end(), [&tr](const int idx) {
        tr.cancel_ticket_by_id(idx);
    });
}