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
    static const auto SIZE = 3;
    static const auto TYPES = std::array<Type, SIZE>{ Type::ORDERED, Type::RESERVED, Type::CANCELLED };

    /**
     * @brief Method that converts string to Type.
     * @param std::string representing a string to convert.
     * @return Type representing a converted string.
     */
    static Type from_string(const std::string& value)
    {
        auto lowercase = std::string{ Utils::convert_string_to_lowercase(value) };

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
        auto ticket_states_str = std::array<std::string, SIZE>{ "ORDERED", "RESERVED", "CANCELLED" };
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
            throw std::out_of_range("No ticket state at index no. " + std::to_string(pos));
        }

        return TYPES[pos];
    }
}

using ticket_state = TicketState::Type;

#endif //CINEMAS_TICKET_STATE_HPP
