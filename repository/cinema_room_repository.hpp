//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
#define CINEMAS_CINEMA_ROOM_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/cinema_room.hpp"
#include "../connection/db_connection.hpp"

class CinemaRoomRepository {
public:
    void insert(const CinemaRoom& cinema_room);
    void update(const int id, const CinemaRoom& cinema_room);
    void remove(const int id);
};


#endif //CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
