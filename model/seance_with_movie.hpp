//
// Created by Cezary Petryka on 07.11.2020.
//

#ifndef CINEMAS_SEANCE_WITH_MOVIE_HPP
#define CINEMAS_SEANCE_WITH_MOVIE_HPP

#include "../libs/libs.hpp"

struct SeanceWithMovie {
    int seance_id;
    int seance_movie_id;
    int seance_cinema_room_id;
    std::string seance_date_time;
    std::string movie_title;
    std::string movie_genre;
    std::string movie_author;

};

#endif //CINEMAS_SEANCE_WITH_MOVIE_HPP
