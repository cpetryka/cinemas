//
// Created by Cezary Petryka on 07.11.2020.
//

#ifndef CINEMAS_SEANCE_WITH_MOVIE_HPP
#define CINEMAS_SEANCE_WITH_MOVIE_HPP

#include "../libs/libs.hpp"
#include "date_time.hpp"

struct SeanceWithMovie {
    int seance_id;
    int seance_movie_id;
    int seance_cinema_room_id;
    // std::string seance_date_time;
    DateTime seance_date_time;
    std::string movie_title;
    std::string movie_genre;
    std::string movie_author;

    friend std::ostream& operator<<(std::ostream& out, const SeanceWithMovie& swm) {
        return out << swm.movie_title << " CREATED BY " << swm.movie_author << "; " << swm.seance_date_time;
    }
};

#endif //CINEMAS_SEANCE_WITH_MOVIE_HPP
