//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_ROOM_HPP
#define CINEMAS_CINEMA_ROOM_HPP

#include "../libs/libs.hpp"

struct CinemaRoom {
    int id;
    std::string name;
    int cinema_id;
    int rows;
    int places;
};

#endif //CINEMAS_CINEMA_ROOM_HPP
