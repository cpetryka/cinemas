//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_REPOSITORY_HPP
#define CINEMAS_CINEMA_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/cinema.hpp"
#include "../connection/db_connection.hpp"

/**
 * @brief Class that is responsible for executing queries on 'cinema' table.
 */
class CinemaRepository {
public:
    /**
     * @brief Method that allows to insert new cinema to database.
     * @param Cinema object to insert.
     */
    void insert(const Cinema& cinema);

    /**
     * @brief Methods that allows to update a cinema at a given id.
     * @param int id of cinema to update.
     * @param Cinema object to update.
     */
    void update(const int id, const Cinema& cinema);

    /**
     * @brief Method that allows to remove a cinema at a given id.
     * @param int id of cinema to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a position of cinema in database.
     * @param Cinema object to find.
     * @return std::optional<int> position of cinema in database.
     */
    static std::optional<int> find_pos(const Cinema& cinema);
};


#endif //CINEMAS_CINEMA_REPOSITORY_HPP
