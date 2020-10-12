//
// Created by Cezary Petryka on 12.10.2020.
//

#ifndef CINEMAS_DB_CONNECTION_HPP
#define CINEMAS_DB_CONNECTION_HPP

#include "../libs/libs.hpp"

class DbConnection
{
private:
    static DbConnection* instance;
    DbConnection();

    const std::string database_name = "ticket_office.db";
    sqlite3* connection = nullptr;

    void create_tables() const;
public:
    static DbConnection* get_instance();
    sqlite3* get_connection() const;
};

#endif //CINEMAS_DB_CONNECTION_HPP
