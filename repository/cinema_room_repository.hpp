//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
#define CINEMAS_CINEMA_ROOM_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../model/cinema_room.hpp"
#include "../repository/seat_repository.hpp"
#include "../connection/db_connection.hpp"

/**
 * @brief Class that is responsible for executing queries on 'cinema_room' table.
 */
class CinemaRoomRepository {
    std::string from_unsigned_char_to_std_string(const unsigned char* value);
public:
    /**
     * @brief Method that allows to insert new cinema_room to database.
     * @param CinemaRoom object to insert.
     */
    void insert(const CinemaRoom& cinema_room);

    /**
     * @brief Methods that allows to update a cinema_room at a given id.
     * @param int id of cinema_room to update.
     * @param CinemaRoom object to update.
     */
    void update(const int id, const CinemaRoom& cinema_room);

    /**
     * @brief Method that allows to remove a cinema_room at a given id.
     * @param int id of cinema_room to remove.
     */
    void remove(const int id);

    /**
     * @brief Method that allows to find a position of cinema_room by name in database.
     * @param CinemaRoom object to find.
     * @return std::optional<int> position of cinema_room in database.
     */
    static std::optional<int> find_pos_by_name(const std::string& name);

    /**
     * @brief Method that allows to find a position of cinema_room in database.
     * @param CinemaRoom object to find.
     * @return std::optional<int> position of cinema_room in database.
     */
    static std::optional<int> find_pos(const CinemaRoom& cinema_room);

    /**
     * @brief Method that allows to find a cinema_room by id.
     * @param int id of cinema_room to find.
     * @return std::optional<std::unique_ptr<CinemaRoom>> cinema_room object wrapped by std::optional.
     */
    std::optional<std::unique_ptr<CinemaRoom>> find_by_id(const int idx);

    /**
     * @brief Method that allows to find all seats in given room.
     * @param int room_id
     * @param int rows
     * @param int places
     * @return std::vector<std::unique_ptr<Seat>> vector of seats.
     */
    static std::vector<std::unique_ptr<Seat>> find_all_seats_in_given_room(const int room_id, const int rows, const int places);
};


#endif //CINEMAS_CINEMA_ROOM_REPOSITORY_HPP
