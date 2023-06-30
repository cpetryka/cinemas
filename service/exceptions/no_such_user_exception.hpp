//
// Created by Cezary Petryka on 30/06/2023.
//

#ifndef CINEMAS_NO_SUCH_USER_EXCEPTION_HPP
#define CINEMAS_NO_SUCH_USER_EXCEPTION_HPP

#include <string>
#include <stdexcept>

class NoSuchUserException : public std::runtime_error {
public:
    explicit NoSuchUserException(const std::string& what_arg) : runtime_error(what_arg) {};
};

#endif //CINEMAS_NO_SUCH_USER_EXCEPTION_HPP
