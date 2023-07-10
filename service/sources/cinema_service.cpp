//
// Created by Cezary Petryka on 21.10.2020.
//

#include "../cinema_service.hpp"

void CinemaService::add_cinemas_to_the_database(const std::string &file_name) const {
    json cinemas_data = Utils::get_data_from_json_file(file_name);

    // Add cinemas
    std::ranges::for_each(cinemas_data, [](const auto& cinema_data) {
        // Create cinema object
        Cinema cinema_tmp = {0, cinema_data["name"], cinema_data["city"]};

        // If there is no such cinema, add it
        if(!CinemaRepository::find_pos(cinema_tmp).has_value()) {
            CinemaRepository::insert(cinema_tmp);
        }

        // Add rooms
        std::ranges::for_each(cinema_data["cinema_rooms"], [&cinema_tmp](const auto& one_cinema_room) {
            // Create cinema room object
            CinemaRoom cinema_room_tmp = CinemaRoom{0, one_cinema_room["name"], CinemaRepository::find_pos(cinema_tmp).value(), one_cinema_room["rows"], one_cinema_room["places"]};

            // If there is no such cinema room, add it
            if(!CinemaRoomRepository::find_pos(cinema_room_tmp).has_value()) {
                CinemaRoomRepository::insert(cinema_room_tmp);
            }

            // Add seats
            auto one_cinema_room_pos = CinemaRoomRepository::find_pos(cinema_room_tmp).value();

            for(auto i = 1; i <= one_cinema_room["rows"]; ++i) {
                for(auto j = 1; j <= one_cinema_room["places"]; ++j) {
                    // Create seat object
                    Seat s{0, one_cinema_room_pos, i, j};

                    // If there is no such seat, add it
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