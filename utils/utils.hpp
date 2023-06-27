//
// Created by Cezary Petryka on 03/05/2023.
//

#ifndef CINEMAS_UTILS_HPP
#define CINEMAS_UTILS_HPP

#include "../libs/headers.hpp"

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

    /**
     * @brief Method that allows to convert sqlite3_column_text to string.
     * @param const unsigned char* representing value to convert.
     * @return std::string representing converted value.
     */
    static std::string convert_sqlite3_column_text_to_string(const unsigned char* value);

    /**
     * @brief Method that gets data from json file.
     * @param std::string representing file name.
     * @return json object.
     * */
    static json get_data_from_json_file(const std::string &file_name);
};

#endif //CINEMAS_UTILS_HPP
