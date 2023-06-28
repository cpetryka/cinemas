//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_CUSTOMER_GENDER_HPP
#define CINEMAS_CUSTOMER_GENDER_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"

/**
 * @brief Represents a customer gender.
 */
namespace CustomerGender
{
    /**
     * @brief Enum in which the possible options are stored.
     */
    enum class Type
    {
        MALE = 0, FEMALE = 1
    };

    /**
     * @brief Array of all possible options. It works as a helper for other methods.
     */
    static Type Types[] = { Type::MALE, Type::FEMALE };
    static int SIZE = 2;

    /**
     * @brief Method that converts string to Type.
     * @param std::string representing a string to convert.
     * @return Type representing a converted string.
     */
    static Type from_string(const std::string& value)
    {
        if (Utils::convert_string_to_lowercase(value) == "male")
        {
            return Type::MALE;
        }
        else
        {
            return Type::FEMALE;
        }
    }

    /**
     * @brief Method that converts Type to string.
     * @param Type representing a type to convert.
     * @return std::string representing a converted type.
     */
    static std::string to_string(Type type)
    {
        std::string customer_genders_str[] = { "MALE", "FEMALE" };
        return customer_genders_str[static_cast<int>(type)];
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
            throw std::runtime_error("No gender at index no " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using customer_gender = CustomerGender::Type;

#endif //CINEMAS_CUSTOMER_GENDER_HPP
