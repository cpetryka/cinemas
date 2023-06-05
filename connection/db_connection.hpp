//
// Created by Cezary Petryka on 12.10.2020.
//

#ifndef CINEMAS_DB_CONNECTION_HPP
#define CINEMAS_DB_CONNECTION_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents connection to database.
 */
class DbConnection
{
private:
    /**
     * @brief Instance of DbConnection class.
     */
    static DbConnection* instance;

    /**
     * @brief Private constructor.
     */
    DbConnection();

    /**
     * @brief Connection details (name of database etc.).
     */
    const std::string DATABASE_NAME = "ticketoffice.db";
    sqlite3* connection = nullptr;

    /**
     * @brief Method that creates tables in database.
     */
    void create_tables() const;
public:
    /**
     * @brief Gets instance of DbConnection class.
     * @return Instance of DbConnection class.
     */
    static DbConnection* get_instance();

    /**
     * @brief Gets connection to database.
     * @return Connection to database.
     */
    sqlite3* get_connection() const;
};

#endif //CINEMAS_DB_CONNECTION_HPP
