//
// Created by Cezary Petryka on 20.01.2021.
//

#include "../seance.hpp"

Seance::Seance(const int id, const int movie_id, const int cinema_room_id, const std::string& date_time) : id{id},
movie_id{movie_id}, cinema_room_id{cinema_room_id}, date_time{std::make_unique<DateTime>(date_time)} {}

Seance::Seance(Seance& seance) : id{seance.id}, movie_id{seance.movie_id}, cinema_room_id{seance.cinema_room_id},
    date_time{std::make_unique<DateTime>(*seance.date_time)} {}

Seance::Seance(Seance&& seance) : id{seance.id}, movie_id{seance.movie_id}, cinema_room_id{seance.cinema_room_id},
    date_time{std::make_unique<DateTime>(*seance.date_time)} {
    seance.date_time = nullptr;
}

Seance& Seance::operator=(Seance& seance) {
    if(this == &seance) {
        return *this;
    }

    id = seance.id;
    movie_id = seance.movie_id;
    cinema_room_id = seance.cinema_room_id;
    date_time = std::make_unique<DateTime>(*seance.date_time);

    return *this;
}

Seance& Seance::operator=(Seance&& seance) {
    if(this == &seance) {
        return *this;
    }

    id = seance.id;
    movie_id = seance.movie_id;
    cinema_room_id = seance.cinema_room_id;
    date_time = std::make_unique<DateTime>(*seance.date_time);
    seance.date_time = nullptr;

    return *this;
}