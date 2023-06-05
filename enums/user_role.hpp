//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_USER_ROLE_HPP
#define CINEMAS_USER_ROLE_HPP

#include "../libs/headers.hpp"

/**
 * @brief Represents a user role.
 */
namespace UserRole
{
    /**
     * @brief Enum in which the possible options are stored.
     */
    enum class Type
    {
        USER = 0, CUSTOMER = 1
    };

    /**
     * @brief Array of all possible options. It works as a helper for other methods.
     */
    static Type Types[] = { Type::USER, Type::CUSTOMER };
    static int SIZE = 2;

    /**
     * @brief Method that converts string to Type.
     * @param std::string representing a string to convert.
     * @return Type representing a converted string.
     */
    static Type from_string(const std::string& value)
    {
        if (Utils::convert_string_to_lowercase(value) == "customer")
        {
            return Type::CUSTOMER;
        }
        else
        {
            return Type::USER;
        }
    }

    /**
     * @brief Method that converts Type to string.
     * @param Type representing a type to convert.
     * @return std::string representing a converted type.
     */
    static std::string to_string(Type type)
    {
        std::string user_roles_str[] = { "USER", "CUSTOMER" };
        return user_roles_str[static_cast<int>(type)];
    }

    /**
     * @brief Method that returns Type at given position.
     * @param int representing a position.
     * @return Type at given position.
     */
    static Type at(const int pos)
    {
        if (pos < 0 || pos >= SIZE)
        {
            throw std::runtime_error("No role at index no " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using user_role = UserRole::Type;

#endif //CINEMAS_USER_ROLE_HPP