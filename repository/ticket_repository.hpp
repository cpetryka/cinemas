//
// Created by Cezary Petryka on 20.10.2020.
//

#ifndef CINEMAS_TICKET_REPOSITORY_HPP
#define CINEMAS_TICKET_REPOSITORY_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"
#include "../model/ticket.hpp"
#include "../connection/db_connection.hpp"
#include "../utils/date_time.hpp"
#include "exceptions/table_operation_exception.hpp"

/**
 * @brief Class that is responsible for executing queries on 'ticket' table.
 */
struct TicketRepository {
    /**
     * @brief Method that allows to insert new ticket to database.
     * @param Ticket object to insert.
     */
    static void insert(const Ticket& ticket);

    /**
     * @brief Methods that allows to update a ticket at a given id.
     * @param int id of ticket to update.
     * @param Ticket object to update.
     */
    static void update(const int id, const Ticket& ticket);

    /**
     * @brief Method that allows to remove a ticket at a given id.
     * @param int id of ticket to remove.
     */
    static void remove(const int id);

    /**
     * @brief Method that allows to cancel of ticket at a given id.
     * @param int id of ticket to cancel.
     */
    static void cancel_ticket_by_id(const int idx);

    /**
     * @brief Method that allows to find reserved seats for a given seance.
     * @param int id of seance.
     * @return std::vector<int> vector of reserved seats.
     */
    static std::vector<int> find_reserved_seats(const int seance_id);

    /**
     * @brief Method that allows to find a ticket by id.
     * @param int id of ticket to find.
     * @return std::optional<std::unique_ptr<Ticket>> ticket object wrapped by std::optional.
     */
    static std::optional<std::unique_ptr<Ticket>> find_by_id(const int idx);

    /**
     * @brief Method that allows to find reservations to cancel.
     * @return std::optional<int> positions of reservations to cancel.
     */
    static std::vector<int> find_reservations_to_cancel();
};


#endif //CINEMAS_TICKET_REPOSITORY_HPP
