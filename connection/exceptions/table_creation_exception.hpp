//
// Created by Cezary Petryka on 28/06/2023.
//

#ifndef CINEMAS_TABLE_CREATION_EXCEPTION_HPP
#define CINEMAS_TABLE_CREATION_EXCEPTION_HPP

#include <string>
#include <stdexcept>

class TableCreationException : public std::runtime_error {
public:
    explicit TableCreationException(const std::string& message) : std::runtime_error(message) {}
};

#endif //CINEMAS_TABLE_CREATION_EXCEPTION_HPP
