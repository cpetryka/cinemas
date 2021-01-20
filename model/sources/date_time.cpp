//
// Created by Cezary Petryka on 19.01.2021.
//

#include "../date_time.hpp"

std::vector<int> DateTime::convert_date_time_str_into_parts_of_date(const std::string &date_time_str) const {
    std::vector<int> parts_of_date;

    parts_of_date.emplace_back(std::stoi(date_time_str.substr(0, 4)));
    parts_of_date.emplace_back(std::stoi(date_time_str.substr(5, 2)));
    parts_of_date.emplace_back(std::stoi(date_time_str.substr(8, 2)));

    return parts_of_date;
}

year_month_day DateTime::convert_data_into_date(const std::string &date_time_str) const {
    auto parts_of_date = convert_date_time_str_into_parts_of_date(date_time_str);
    return year_month_day{ year{parts_of_date.at(0)}, month{static_cast<unsigned int>(parts_of_date.at(1))}, day{static_cast<unsigned int>(parts_of_date.at(2))} };
}

int DateTime::convert_date_time_str_into_seconds_since_midnight(const std::string &date_time_str) const {
    std::string time_str = date_time_str.substr(date_time_str.size() - 8);
    auto hours = std::stoi(time_str.substr(0,2));
    auto minutes = std::stoi(time_str.substr(3,2));
    auto seconds = std::stoi(time_str.substr(6,2));

    return hours * 3600 + minutes * 60 + seconds;
}

DateTime::DateTime(const std::string &date_time_str) {
    date = convert_data_into_date(date_time_str);
    time = time_of_day<std::chrono::seconds> { std::chrono::seconds(convert_date_time_str_into_seconds_since_midnight(date_time_str)) };
}

year_month_day DateTime::get_date() const {
    return date;
}

time_of_day<std::chrono::seconds> DateTime::get_time() const {
    return time;
}

std::string DateTime::convert_date_into_string() const {
    std::stringstream ss;
    ss << date;
    return ss.str();
}

std::string DateTime::convert_time_into_string() const {
    std::stringstream ss;
    ss << time;
    return ss.str();
}

std::string DateTime::convert_date_and_time_into_string() const {
    std::stringstream ss;
    ss << date << " " << time;
    return ss.str();
}

std::ostream &operator<<(std::ostream &out, const DateTime &date_time) {
    return out << date_time.date << " " << date_time.time;
}