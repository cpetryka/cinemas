//
// Created by Cezary Petryka on 03/05/2023.
//

#ifndef CINEMAS_UTILS_HPP
#define CINEMAS_UTILS_HPP

#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

/**
 * @brief Class that contains useful methods.
 */
struct Utils {
    /**
     * @brief Method that allows to convert string to lowercase.
     * @param std::string representing string to convert.
     * @return std::string representing converted string.
     */
    static std::string convert_string_to_lowercase(const std::string& str);

    /**
     * @brief Method that allows to convert string to vector.
     * @param std::string representing string to convert.
     * @param char representing separator.
     * @return std::vector<std::string> representing converted string.
     */
    static std::vector<std::string> convert_string_to_vector(const std::string& str, const char separator);
};

#endif //CINEMAS_UTILS_HPP
