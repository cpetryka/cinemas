//
// Created by Cezary Petryka on 19.01.2021.
//

#include "../date_time_utils.hpp"

std::string DateTimeUtils::get_current_date_and_time_as_string() {
    const std::chrono::time_point now{std::chrono::system_clock::now()};
    const std::chrono::zoned_time zt{std::chrono::current_zone(), now};
    return std::format("{:%Y-%m-%d %H:%M:%S}", zt);
}