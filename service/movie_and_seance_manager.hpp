//
// Created by Cezary Petryka on 25.10.2020.
//

#ifndef CINEMAS_MOVIE_AND_SEANCE_MANAGER_HPP
#define CINEMAS_MOVIE_AND_SEANCE_MANAGER_HPP

#include "../repository/movie_repository.hpp"
#include "../repository/seance_repository.hpp"
#include "../repository/cinema_repository.hpp"
#include "../repository/cinema_room_repository.hpp"

class MovieAndSeanceManager {
    json get_data_from_json_file(const std::string &file_name) const;
public:
    explicit MovieAndSeanceManager() = default;
    explicit MovieAndSeanceManager(const std::string& movies_file_name, const std::string& seances_file_name);

    void add_movies_to_the_database(const std::string &file_name) const;
    void add_seances_to_the_database(const std::string &file_name) const;
};


#endif //CINEMAS_MOVIE_AND_SEANCE_MANAGER_HPP
