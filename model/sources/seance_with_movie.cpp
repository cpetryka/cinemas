//
// Created by Cezary Petryka on 20.01.2021.
//

#include "../seance_with_movie.hpp"

SeanceWithMovie::SeanceWithMovie(const int seance_id, const int seance_movie_id, const int seance_cinema_room_id,
                                 const std::string& seance_date_time, const std::string& movie_title,
                                 const std::string& movie_genre, const std::string& movie_author)
                                 : seance_id{seance_id}, seance_movie_id{seance_movie_id},
                                 seance_cinema_room_id{seance_cinema_room_id},
                                 seance_date_time{std::make_unique<DateTime>(DateTime{seance_date_time})},
                                 movie_title{movie_title}, movie_genre{movie_genre}, movie_author{movie_author} {}

SeanceWithMovie::SeanceWithMovie(SeanceWithMovie& swm) : seance_id{swm.seance_id}, seance_movie_id{swm.seance_movie_id},
    seance_cinema_room_id{swm.seance_cinema_room_id}, seance_date_time{std::make_unique<DateTime>(DateTime{*swm.seance_date_time})},
    movie_title{swm.movie_title}, movie_genre{swm.movie_genre}, movie_author{swm.movie_author} {}

SeanceWithMovie::SeanceWithMovie(SeanceWithMovie&& swm) : seance_id{swm.seance_id}, seance_movie_id{swm.seance_movie_id},
    seance_cinema_room_id{swm.seance_cinema_room_id}, seance_date_time{std::make_unique<DateTime>(DateTime{*swm.seance_date_time})},
    movie_title{swm.movie_title}, movie_genre{swm.movie_genre}, movie_author{swm.movie_author} {
    swm.seance_date_time = nullptr;
}

SeanceWithMovie& SeanceWithMovie::operator=(SeanceWithMovie& swm) {
    if(this == &swm) {
        return *this;
    }

    seance_id = swm.seance_id;
    seance_movie_id = swm.seance_movie_id;
    seance_cinema_room_id = swm.seance_cinema_room_id;
    seance_date_time = std::make_unique<DateTime>(DateTime{*swm.seance_date_time});
    movie_title = swm.movie_title;
    movie_genre = swm.movie_genre;
    movie_author = swm.movie_author;

    return *this;
}

SeanceWithMovie& SeanceWithMovie::operator=(SeanceWithMovie&& swm) {
    if(this == &swm) {
        return *this;
    }

    seance_id = swm.seance_id;
    seance_movie_id = swm.seance_movie_id;
    seance_cinema_room_id = swm.seance_cinema_room_id;
    seance_date_time = std::make_unique<DateTime>(DateTime{*swm.seance_date_time});
    swm.seance_date_time = nullptr;
    movie_title = swm.movie_title;
    movie_genre = swm.movie_genre;
    movie_author = swm.movie_author;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const SeanceWithMovie& swm) {
    return out << swm.movie_title << " CREATED BY " << swm.movie_author << "; " << *swm.seance_date_time;
}