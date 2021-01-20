//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_SEANCE_HPP
#define CINEMAS_SEANCE_HPP

#include "../libs/libs.hpp"
#include "date_time.hpp"

struct Seance {
    int id;
    int movie_id;
    int cinema_room_id;
    std::unique_ptr<DateTime> date_time;

    Seance(const int id, const int movie_id, const int cinema_room_id, const std::string& date_time);

    Seance(Seance& seance);
    Seance(Seance&& seance);

    Seance& operator=(Seance& seance);
    Seance& operator=(Seance&& seance);
};

#endif //CINEMAS_SEANCE_HPP
