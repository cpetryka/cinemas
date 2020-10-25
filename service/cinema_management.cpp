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

    CinemaRoom cinema_room_temp;
    CinemaRoomRepository crr;

    std::for_each(data.begin(), data.end(), [&cinema_temp, &cr, &cinema_room_temp, &crr](const auto& one_cinema) {
        // Add cinema
        cinema_temp = {0, one_cinema["name"], one_cinema["city"]};

        if(cr.find(cinema_temp) == -1) {
            cr.insert(cinema_temp);
        }

        // Add rooms
        std::for_each(one_cinema["cinema_rooms"].begin(), one_cinema["cinema_rooms"].end(), [&cinema_room_temp, &crr, &cr, &cinema_temp](const auto& one_cinema_room) {
            cinema_room_temp = CinemaRoom{0, one_cinema_room["name"], cr.find(cinema_temp), one_cinema_room["rows"], one_cinema_room["places"]};
            auto one_cinema_room_pos = crr.find_pos_by_name(one_cinema_room["name"]);


            if(one_cinema_room_pos == -1) {
                crr.insert(cinema_room_temp);
            }
            else {
                crr.update(one_cinema_room_pos, cinema_room_temp);
            }
        });
    });
}

CinemaManagement::CinemaManagement(const std::string &file_name) {
    add_datas_to_the_database(file_name);
}