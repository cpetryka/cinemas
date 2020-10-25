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

    std::for_each(data.begin(), data.end(), [](const auto& one_cinema) {
        // Add cinema
        Cinema cinema_tmp = {0, one_cinema["name"], one_cinema["city"]};
        CinemaRepository cr;

        if(cr.find_pos(cinema_tmp) == -1) {
            cr.insert(cinema_tmp);
        }

        // Add rooms
        std::for_each(one_cinema["cinema_rooms"].begin(), one_cinema["cinema_rooms"].end(), [&cr, &cinema_tmp](const auto& one_cinema_room) {
            CinemaRoom cinema_room_tmp = CinemaRoom{0, one_cinema_room["name"], cr.find_pos(cinema_tmp), one_cinema_room["rows"], one_cinema_room["places"]};
            CinemaRoomRepository crr;

            if(crr.find_pos_by_name(one_cinema_room["name"]) == -1) {
                crr.insert(cinema_room_tmp);
            }
            else {
                crr.update(crr.find_pos_by_name(one_cinema_room["name"]), cinema_room_tmp);
            }

            // Add seats
            auto one_cinema_room_pos = crr.find_pos_by_name(one_cinema_room["name"]);
            SeatRepository sr;

            for(auto i = 1; i <= one_cinema_room["rows"]; ++i) {
                for(auto j = 1; j <= one_cinema_room["places"]; ++j) {
                    Seat s{0, one_cinema_room_pos, i, j};

                    if(sr.find_pos(s) == -1) {
                        sr.insert(s);
                    }
                }
            }
        });
    });
}

CinemaManagement::CinemaManagement(const std::string &file_name) {
    add_datas_to_the_database(file_name);
}