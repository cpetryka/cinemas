//
// Created by Cezary Petryka on 19.01.2021.
//

#ifndef CINEMAS_DATE_TIME_HPP
#define CINEMAS_DATE_TIME_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that represents date and time.
 */
class DateTime {
    year_month_day date;
    time_of_day<std::chrono::seconds> time;

    /**
     * @brief Converts date and time string into parts of date.
     * @param std::string representing date and time.
     * @return std::vector<int> representing parts of date.
     */
    std::vector<int> convert_date_time_str_into_parts_of_date(const std::string &date_time_str) const;

    /**
     * @brief Converts date and time string into parts of time.
     * @param std::string representing date and time.
     * @return std::vector<int> representing parts of time.
     */
    year_month_day convert_data_into_date(const std::string &date_time_str) const;

    /**
     * @brief Converts date and time string into parts of time.
     * @param std::string representing date and time.
     * @return std::vector<int> representing parts of time.
     */
    int convert_date_time_str_into_seconds_since_midnight(const std::string &date_time_str) const;


    /**
     * @brief Indicates current date.
     * @return year_month_day representing current date.
     */
    year_month_day indicate_current_date() const;

    /**
     * @brief Indicates current time.
     * @return time_of_day<std::chrono::seconds> representing current time.
     */
    time_of_day<std::chrono::seconds> indicate_current_time() const;
public:
    DateTime();
    DateTime(const std::string& date_time_str);

    /**
     * @brief Getter for date.
     * @return year_month_day representing date.
     */
    year_month_day get_date() const;

    /**
     * @brief Getter for time.
     * @return time_of_day<std::chrono::seconds> representing time.
     */
    time_of_day<std::chrono::seconds> get_time() const;


    /**
     * @brief Converts date into string.
     * @return std::string representing date.
     */
    std::string convert_date_into_string() const;

    /**
     * @brief Converts time into string.
     * @return std::string representing time.
     */
    std::string convert_time_into_string() const;

    /**
     * @brief Converts date and time into string.
     * @return std::string representing date and time.
     */
    std::string convert_date_and_time_into_string() const;

    friend std::ostream& operator<<(std::ostream& out, const DateTime& date_time);
};


#endif //CINEMAS_DATE_TIME_HPP
