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
    // std::string date_time;
    DateTime date_time;
};

#endif //CINEMAS_SEANCE_HPP
