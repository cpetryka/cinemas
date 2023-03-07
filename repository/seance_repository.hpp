//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_SEANCE_REPOSITORY_HPP
#define CINEMAS_SEANCE_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../model/seance.hpp"
#include "../model/seance_with_movie.hpp"
#include "../connection/db_connection.hpp"

class SeanceRepository {
    static std::string from_unsigned_char_to_std_string(const unsigned char* value);
    static int convert_date_time_str_into_seconds_since_midnight(const std::string& date_time_str);

public:
    void insert(const Seance& seance);
    void update(const int id, const Seance& seance);
    void remove(const int id);
    static std::optional<int> find_pos(const Seance& seance);
    static std::vector<std::unique_ptr<SeanceWithMovie>> find_by_parameters(const std::string& genre, const std::string& city, const std::string& date, const std::string& time);
};


#endif //CINEMAS_SEANCE_REPOSITORY_HPP
