//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_SEANCE_REPOSITORY_HPP
#define CINEMAS_SEANCE_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/seance.hpp"
#include "../model/seance_with_movie.hpp"
#include "../connection/db_connection.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'seance' table.
 */
class SeanceRepository {
    static int convert_date_time_str_into_seconds_since_midnight(const std::string& date_time_str);
public:
    /**
     * @brief Method that allows to insert new seance to database.
     * @param Seance object to insert.
     */
    void insert(const Seance& seance);

    /**
     * @brief Methods that allows to update a seance at a given id.
     * @param int id of seance to update.
     * @param Seance object to update.
     */
    void update(const int id, const Seance& seance);

    /**
     * @brief Method that allows to remove a seance at a given id.
     * @param int id of seance to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a seance in database.
     * @param Seance object to find.
     * @return std::optional<int> position of seance in database.
     */
    static std::optional<int> find_pos(const Seance& seance);

    /**
     * @brief Method that allows to find a seance in database by their title and author.
     * @param std::string title of seance to find.
     * @param std::string author of seance to find.
     * @return std::optional<int> position of seance in database.
     */
    static std::vector<std::unique_ptr<SeanceWithMovie>> find_by_parameters(const std::string& genre, const std::string& city, const std::string& date, const std::string& time);
};


#endif //CINEMAS_SEANCE_REPOSITORY_HPP
