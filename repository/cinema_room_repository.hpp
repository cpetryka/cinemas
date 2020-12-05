//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
#define CINEMAS_CINEMA_ROOM_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/cinema_room.hpp"
#include "../repository/seat_repository.hpp"
#include "../connection/db_connection.hpp"

class CinemaRoomRepository {
    std::string from_unsigned_char_to_std_string(const unsigned char* value);
public:
    void insert(const CinemaRoom& cinema_room);
    void update(const int id, const CinemaRoom& cinema_room);
    void remove(const int id);
    int find_pos_by_name(const std::string& name);
    std::optional<std::unique_ptr<CinemaRoom>> find_by_id(const int idx);
    static std::vector<std::unique_ptr<Seat>> find_all_seats_in_given_room(const int room_id, const int rows, const int places);
};


#endif //CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
