//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_REPOSITORY_HPP
#define CINEMAS_CINEMA_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/cinema.hpp"
#include "../connection/db_connection.hpp"

class CinemaRepository {
public:
    void insert(const Cinema& cinema);
    void update(const int id, const Cinema& cinema);
    void remove(const int id);
};


#endif //CINEMAS_CINEMA_REPOSITORY_HPP
