//
// Created by Cezary Petryka on 21.10.2020.
//

#include "../cinema_service.hpp"

void CinemaService::add_cinemas_to_the_database(const std::string &file_name) const {
    json data = Utils::get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_cinema) {
        // Add cinema
        Cinema cinema_tmp = {0, one_cinema["name"], one_cinema["city"]};

        // If there is no such cinema, this adds it
        if(!CinemaRepository::find_pos(cinema_tmp).has_value()) {
            CinemaRepository::insert(cinema_tmp);
        }

        // Add rooms
        std::for_each(one_cinema["cinema_rooms"].begin(), one_cinema["cinema_rooms"].end(), [&cinema_tmp](const auto& one_cinema_room) {
            CinemaRoom cinema_room_tmp = CinemaRoom{0, one_cinema_room["name"], CinemaRepository::find_pos(cinema_tmp).value(), one_cinema_room["rows"], one_cinema_room["places"]};

            if(!CinemaRoomRepository::find_pos(cinema_room_tmp).has_value()) {
                CinemaRoomRepository::insert(cinema_room_tmp);
            }

            // Add seats
            auto one_cinema_room_pos = CinemaRoomRepository::find_pos(cinema_room_tmp).value();

            for(auto i = 1; i <= one_cinema_room["rows"]; ++i) {
                for(auto j = 1; j <= one_cinema_room["places"]; ++j) {
                    Seat s{0, one_cinema_room_pos, i, j};

                    if(!SeatRepository::find_pos(s).has_value()) {
                        SeatRepository::insert(s);
                    }
                }
            }
        });
    });
}

CinemaService::CinemaService(const std::string &file_name) {
    add_cinemas_to_the_database(file_name);
}