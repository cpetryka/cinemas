//
// Created by Cezary Petryka on 19.01.2021.
//

#ifndef CINEMAS_DATE_TIME_UTILS_HPP
#define CINEMAS_DATE_TIME_UTILS_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents date and time.
 */
struct DateTimeUtils {
    /**
     * @brief Gets current date and time as string in format: YYYY-MM-DD HH:MM:SS.
     * @return std::string representing current date and time.
     */
    static std::string get_current_date_and_time_as_string();
};


#endif //CINEMAS_DATE_TIME_UTILS_HPP
