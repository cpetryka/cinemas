//
// Created by Cezary Petryka on 07.11.2020.
//

#ifndef CINEMAS_SEANCE_WITH_MOVIE_HPP
#define CINEMAS_SEANCE_WITH_MOVIE_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents seance with movie.
 */
struct SeanceWithMovie {
    int seance_id;
    int seance_movie_id;
    int seance_cinema_room_id;
    std::string seance_date_time;
    std::string movie_title;
    std::string movie_genre;
    std::string movie_author;

    SeanceWithMovie(const int seance_id, const int seance_movie_id, const int seance_cinema_room_id,
        const std::string& seance_date_time, const std::string& movie_title, const std::string& movie_genre,
        const std::string& movie_author) : seance_id{seance_id}, seance_movie_id{seance_movie_id},
        seance_cinema_room_id{seance_cinema_room_id}, seance_date_time{seance_date_time}, movie_title{movie_title},
        movie_genre{movie_genre}, movie_author{movie_author} {}

    friend std::ostream& operator<<(std::ostream& out, const SeanceWithMovie& swm) {
        return out << swm.movie_title << " CREATED BY " << swm.movie_author << "; " << swm.seance_date_time;
    }
};

#endif //CINEMAS_SEANCE_WITH_MOVIE_HPP
