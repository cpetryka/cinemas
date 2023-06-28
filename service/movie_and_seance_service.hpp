//
// Created by Cezary Petryka on 25.10.2020.
//

#ifndef CINEMAS_MOVIE_AND_SEANCE_SERVICE_HPP
#define CINEMAS_MOVIE_AND_SEANCE_SERVICE_HPP

#include "../utils/utils.hpp"
#include "../repository/movie_repository.hpp"
#include "../repository/seance_repository.hpp"
#include "../repository/cinema_repository.hpp"
#include "../repository/cinema_room_repository.hpp"

/**
 * @brief Class that is responsible for managing movies and seances.
 */
class MovieAndSeanceService {
public:
    explicit MovieAndSeanceService() = default;
    explicit MovieAndSeanceService(const std::string& movies_file_name, const std::string& seances_file_name);

    /**
     * @brief Method that allows to add movies to the database.
     * @param std::string representing file name.
     */
    void add_movies_to_the_database(const std::string &file_name) const;

    /**
     * @brief Method that allows to add seances to the database.
     * @param std::string representing file name.
     */
    void add_seances_to_the_database(const std::string &file_name) const;
};


#endif //CINEMAS_MOVIE_AND_SEANCE_SERVICE_HPP
