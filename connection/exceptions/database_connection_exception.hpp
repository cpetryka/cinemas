//
// Created by Cezary Petryka on 28/06/2023.
//

#ifndef CINEMAS_DATABASE_CONNECTION_EXCEPTION_HPP
#define CINEMAS_DATABASE_CONNECTION_EXCEPTION_HPP

#include <string>
#include <stdexcept>

class DatabaseConnectionException : public std::runtime_error {
public:
    explicit DatabaseConnectionException(const std::string& message) : std::runtime_error(message) {}
};

#endif //CINEMAS_DATABASE_CONNECTION_EXCEPTION_HPP
