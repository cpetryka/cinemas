//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_SEAT_REPOSITORY_HPP
#define CINEMAS_SEAT_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/seat.hpp"
#include "../connection/db_connection.hpp"

class SeatRepository {
public:
    void insert(const Seat& seat);
    void update(const int id, const Seat& seat);
    void remove(const int id);
    static std::optional<int> find_pos(const Seat& seat);
    std::optional<std::unique_ptr<Seat>> find_by_parameters(const int cinema_room_id, const int row, const int place);
};


#endif //CINEMAS_SEAT_REPOSITORY_HPP
