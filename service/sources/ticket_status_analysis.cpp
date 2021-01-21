//
// Created by Cezary Petryka on 18.01.2021.
//

#include "../ticket_status_analysis.hpp"

void TicketStatusAnalysis::analyse_tickets_state() {
    TicketRepository tr;
    auto tickets_to_cancel = tr.find_reservations_to_cancel();

    std::for_each(tickets_to_cancel.begin(), tickets_to_cancel.end(), [&tr](const int idx) {
        tr.cancel_ticket_by_id(idx);
    });
}

void TicketStatusAnalysis::repetitive_ticket_state_analysis() {
    CallBackTimer cbt;
    cbt.start(1000, std::bind(&TicketStatusAnalysis::analyse_tickets_state, this));
}

TicketStatusAnalysis::TicketStatusAnalysis() {
    repetitive_ticket_state_analysis();
}