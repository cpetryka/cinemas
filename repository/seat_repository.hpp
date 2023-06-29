//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_SEAT_REPOSITORY_HPP
#define CINEMAS_SEAT_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/seat.hpp"
#include "../connection/db_connection.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'seat' table.
 */
class SeatRepository {
public:
    /**
     * @brief Method that allows to insert new seat to database.
     * @param Seat object to insert.
     */
    void insert(const Seat& seat);

    /**
     * @brief Methods that allows to update a seat at a given id.
     * @param int id of seat to update.
     * @param Seat object to update.
     */
    void update(const int id, const Seat& seat);

    /**
     * @brief Method that allows to remove a seat at a given id.
     * @param int id of seat to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a seat in database.
     * @param Seat object to find.
     * @return std::optional<int> position of seat in database.
     */
    static std::optional<int> find_pos(const Seat& seat);

    /**
     * @brief Method that allows to find a seat in database by their cinema room id, row and place.
     * @param int cinema_room_id of seat to find.
     * @param int row of seat to find.
     * @param int place of seat to find.
     * @return std::optional<int> position of seat in database.
     */
    static std::optional<std::unique_ptr<Seat>> find_by_parameters(const int cinema_room_id, const int row, const int place);
};


#endif //CINEMAS_SEAT_REPOSITORY_HPP
