//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_SEANCE_REPOSITORY_HPP
#define CINEMAS_SEANCE_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/seance.hpp"
#include "../connection/db_connection.hpp"

class SeanceRepository {
public:
    void insert(const Seance& seance);
    void update(const int id, const Seance& seance);
    void remove(const int id);
    int find_pos(const Seance& seance);
};


#endif //CINEMAS_SEANCE_REPOSITORY_HPP
