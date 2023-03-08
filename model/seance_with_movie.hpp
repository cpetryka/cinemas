//
// Created by Cezary Petryka on 07.11.2020.
//

#ifndef CINEMAS_SEANCE_WITH_MOVIE_HPP
#define CINEMAS_SEANCE_WITH_MOVIE_HPP

#include "../libs/headers.hpp"
#include "../helpers/date_time.hpp"

struct SeanceWithMovie {
    int seance_id;
    int seance_movie_id;
    int seance_cinema_room_id;
    std::unique_ptr<DateTime> seance_date_time;
    std::string movie_title;
    std::string movie_genre;
    std::string movie_author;

    SeanceWithMovie(const int seance_id, const int seance_movie_id, const int seance_cinema_room_id,
                    const std::string& seance_date_time, const std::string& movie_title, const std::string& movie_genre,
                    const std::string& movie_author);

    SeanceWithMovie(SeanceWithMovie& swm);
    SeanceWithMovie(SeanceWithMovie&& swm);

    SeanceWithMovie& operator=(SeanceWithMovie& swm);
    SeanceWithMovie& operator=(SeanceWithMovie&& swm);

    friend std::ostream& operator<<(std::ostream& out, const SeanceWithMovie& swm);
};

#endif //CINEMAS_SEANCE_WITH_MOVIE_HPP
