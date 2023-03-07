//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_USER_ROLE_HPP
#define CINEMAS_USER_ROLE_HPP

#include "../libs/headers.hpp"

namespace UserRole
{
    enum class Type
    {
        USER = 0, CUSTOMER = 1
    };

    static Type Types[] = { Type::USER, Type::CUSTOMER };
    static int SIZE = 2;

    static Type from_string(const std::string& value)
    {
        std::string lowercase = value;
        std::transform(value.begin(), value.end(), lowercase.begin(), [](const char& c) { return tolower(c); });

        if (lowercase == "customer")
        {
            return Type::CUSTOMER;
        }
        else
        {
            return Type::USER;
        }
    }

    static std::string to_string(Type type)
    {
        std::string user_roles_str[] = { "USER", "CUSTOMER" };
        return user_roles_str[static_cast<int>(type)];
    }

    static Type at(const int pos)
    {
        if (pos < 0 || pos >= SIZE)
        {
            throw std::runtime_error("no role with index " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using user_role = UserRole::Type;

#endif //CINEMAS_USER_ROLE_HPP