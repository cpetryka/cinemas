//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_TICKET_STATE_HPP
#define CINEMAS_TICKET_STATE_HPP

#include "../libs/headers.hpp"
#include "../utils/utils.hpp"

/**
 * @brief Represents a ticket state.
 */
namespace TicketState
{
    /**
     * @brief Enum in which the possible options are stored.
     */
    enum class Type
    {
        ORDERED = 0, RESERVED = 1, CANCELLED = 2
    };

    /**
     * @brief Array of all possible options. It works as a helper for other methods.
     */
    static Type Types[] = { Type::ORDERED, Type::RESERVED, Type::CANCELLED };
    static int SIZE = 3;

    /**
     * @brief Method that converts string to Type.
     * @param std::string representing a string to convert.
     * @return Type representing a converted string.
     */
    static Type from_string(const std::string& value)
    {
        std::string lowercase = Utils::convert_string_to_lowercase(value);

        if (lowercase == "ordered")
        {
            return Type::ORDERED;
        }
        else if(lowercase == "reserved") {
            return Type::RESERVED;
        }
        else
        {
            return Type::CANCELLED;
        }
    }

    /**
     * @brief Method that converts Type to string.
     * @param Type representing a type to convert.
     * @return std::string representing a converted type.
     */
    static std::string to_string(Type type)
    {
        std::string ticket_states_str[] = { "ORDERED", "RESERVED", "CANCELLED" };
        return ticket_states_str[static_cast<int>(type)];
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
            throw std::runtime_error("No ticket state at index no " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using ticket_state = TicketState::Type;

#endif //CINEMAS_TICKET_STATE_HPP
