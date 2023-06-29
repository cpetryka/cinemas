//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_MOVIE_REPOSITORY_HPP
#define CINEMAS_MOVIE_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/movie.hpp"
#include "../connection/db_connection.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'movie' table.
 */
class MovieRepository {
public:
    /**
     * @brief Method that allows to insert new movie to database.
     * @param Movie object to insert.
     */
    void insert(const Movie& movie);

    /**
     * @brief Methods that allows to update a movie at a given id.
     * @param int id of movie to update.
     * @param Movie object to update.
     */
    void update(const int id, const Movie& movie);

    /**
     * @brief Method that allows to remove a movie at a given id.
     * @param int id of movie to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a movie in database.
     * @param Movie object to find.
     * @return std::optional<int> position of movie in database.
     */
    static std::optional<int> find_pos(const Movie& movie);

    /**
     * @brief Method that allows to find a movie in database by their title and author.
     * @param std::string title of movie to find.
     * @param std::string author of movie to find.
     * @return std::optional<int> position of movie in database.
     */
    static std::optional<int> find_pos_by_parameters(const std::string& title, const std::string& author);
};


#endif //CINEMAS_MOVIE_REPOSITORY_HPP
