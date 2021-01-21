//
// Created by Cezary Petryka on 18.01.2021.
//

#ifndef CINEMAS_TICKET_STATUS_ANALYSIS_HPP
#define CINEMAS_TICKET_STATUS_ANALYSIS_HPP

#include "../libs/libs.hpp"
#include "../repository/ticket_repository.hpp"

class TicketStatusAnalysis {
    void analyse_tickets_state();
public:
    TicketStatusAnalysis() = default;
};

/*
 * Aplikacja powinna co 15 min analizowac stan zarezerwowanych biletow
 * i te ktore sa zarezerwowane dla seansow, ktore zaczyna
 * za mniej niz pol godziny to nalezy te rezerwacje anulowac.
 * ------------------------------------------------------------------------
 * 1. Wyznaczam aktualna godzine
 * 2. Sprawdzam ktore seanse sa zarezerwowane + zaczynaja sie za mniej niz 30 minut
 * 3. Anulowanie (state: cancelled)
 */

#endif //CINEMAS_TICKET_STATUS_ANALYSIS_HPP
