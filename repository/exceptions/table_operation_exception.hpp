//
// Created by Cezary Petryka on 28/06/2023.
//

#ifndef CINEMAS_TABLE_OPERATION_EXCEPTION_HPP
#define CINEMAS_TABLE_OPERATION_EXCEPTION_HPP

#include <string>
#include <stdexcept>

class TableOperationException : public std::runtime_error {
public:
    explicit TableOperationException(const std::string& message) : std::runtime_error(message) {}
};

#endif //CINEMAS_TABLE_OPERATION_EXCEPTION_HPP
