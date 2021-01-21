//
// Created by Cezary Petryka on 19.01.2021.
//

#ifndef CINEMAS_DATE_TIME_HPP
#define CINEMAS_DATE_TIME_HPP

#include "../libs/libs.hpp"

class DateTime {
    year_month_day date;
    time_of_day<std::chrono::seconds> time;

    std::vector<int> convert_date_time_str_into_parts_of_date(const std::string &date_time_str) const;
    year_month_day convert_data_into_date(const std::string &date_time_str) const;
    int convert_date_time_str_into_seconds_since_midnight(const std::string &date_time_str) const;

    year_month_day indicate_current_date() const;
    time_of_day<std::chrono::seconds> indicate_current_time() const;
public:
    DateTime();
    DateTime(const std::string& date_time_str);

    year_month_day get_date() const;
    time_of_day<std::chrono::seconds> get_time() const;

    std::string convert_date_into_string() const;
    std::string convert_time_into_string() const;
    std::string convert_date_and_time_into_string() const;

    friend std::ostream& operator<<(std::ostream& out, const DateTime& date_time);
};


#endif //CINEMAS_DATE_TIME_HPP
