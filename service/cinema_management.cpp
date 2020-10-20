//
// Created by Cezary Petryka on 21.10.2020.
//

#include "cinema_management.hpp"

json CinemaManagement::get_data_from_json_file(const std::string &file_name) const {
    std::ifstream reading(file_name);
    json j;

    if(reading.is_open()) {
        reading >> j;
        reading.close();
    }
    else {
        throw std::runtime_error{"the file '" + file_name + "' could not be opened"};
    }

    return j;
}

void CinemaManagement::add_datas_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    Cinema cinema_temp;
    CinemaRepository cr;

    std::for_each(data.begin(), data.end(), [&cinema_temp, &cr](const auto& one_cinema) {
        cinema_temp = {0, one_cinema["name"], one_cinema["city"]};

        if(cr.find(cinema_temp) == -1) {
            cr.insert(cinema_temp);
        }
    });
}

CinemaManagement::CinemaManagement(const std::string &file_name) {
    add_datas_to_the_database(file_name);
}