//
// Created by Cezary Petryka on 21.10.2020.
//

#ifndef CINEMAS_CINEMA_SERVICE_HPP
#define CINEMAS_CINEMA_SERVICE_HPP

#include "../repository/cinema_repository.hpp"
#include "../repository/cinema_room_repository.hpp"
#include "../repository/seat_repository.hpp"

/**
 * @brief Class that is responsible for managing cinemas.
 */
class CinemaService {
public:
    explicit CinemaService() = default;
    explicit CinemaService(const std::string& file_name);

    /**
     * @brief Method that allows to add cinemas to the database.
     * @param std::string representing file name.
     */
    void add_cinemas_to_the_database(const std::string &file_name) const;
};

#endif //CINEMAS_CINEMA_SERVICE_HPP
