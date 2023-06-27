//
// Created by Cezary Petryka on 03/05/2023.
//

#include "../utils.hpp"

std::string Utils::convert_string_to_lowercase(const std::string &str) {
    auto str_copy = str;
    std::transform(str.begin(), str.end(), str_copy.begin(), [](const char& c) { return tolower(c); });
    return str_copy;
}

std::vector<std::string> Utils::convert_string_to_vector(const std::string &str, const char separator) {
    std::vector<std::string> strings;
    std::string one_string;
    std::stringstream ss(str);

    while(getline(ss, one_string, separator)) {
        strings.emplace_back(one_string);
    }

    return strings;
}

std::string Utils::convert_sqlite3_column_text_to_string(const unsigned char *value) {
    std::string result = "";
    for (int i = 0; i < strlen(reinterpret_cast<const char*>(value)); ++i) {
        result += value[i];
    }
    return result;
}

json Utils::get_data_from_json_file(const std::string &file_name) {
    std::ifstream read(file_name);
    json j;

    if(read.is_open()) {
        read >> j;
        read.close();
    }
    else {
        throw std::runtime_error{"The file '" + file_name + "' could not be opened."};
    }

    return j;
}
