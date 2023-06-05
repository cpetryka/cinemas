//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_MOVIE_HPP
#define CINEMAS_MOVIE_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents movie.
 */
struct Movie {
    int id;
    std::string title;
    std::string genre;
    std::string author;
};

#endif //CINEMAS_MOVIE_HPP
