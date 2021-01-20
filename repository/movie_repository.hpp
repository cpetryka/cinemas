//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_MOVIE_REPOSITORY_HPP
#define CINEMAS_MOVIE_REPOSITORY_HPP

#include "../libs/libs.hpp"
#include "../model/movie.hpp"
#include "../connection/db_connection.hpp"

class MovieRepository {
public:
    void insert(const Movie& movie);
    void update(const int id, const Movie& movie);
    void remove(const int id);
    static std::optional<int> find_pos(const Movie& movie);
    static std::optional<int> find_pos_by_parameters(const std::string& title, const std::string& author);
};


#endif //CINEMAS_MOVIE_REPOSITORY_HPP
