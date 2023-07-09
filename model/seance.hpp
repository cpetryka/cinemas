//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_SEANCE_HPP
#define CINEMAS_SEANCE_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents seance.
 */
struct Seance {
    int id;
    int movie_id;
    int cinema_room_id;
    std::string date_time;

    Seance(const int id, const int movie_id, const int cinema_room_id, const std::string& date_time)
        : id{id}, movie_id{movie_id}, cinema_room_id{cinema_room_id}, date_time{date_time} {}
};

#endif //CINEMAS_SEANCE_HPP
