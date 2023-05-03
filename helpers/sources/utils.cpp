//
// Created by Cezary Petryka on 03/05/2023.
//

#include "../utils.hpp"

std::string Utils::convert_string_to_lowercase(const std::string &str) {
    auto str_copy = str;
    std::transform(str.begin(), str.end(), str_copy.begin(), [](const char& c) { return tolower(c); });
    return str_copy;
}
