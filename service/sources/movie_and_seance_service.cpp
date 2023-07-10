//
// Created by Cezary Petryka on 25.10.2020.
//

#include "../movie_and_seance_service.hpp"

MovieAndSeanceService::MovieAndSeanceService(const std::string &movies_file_name,
                                             const std::string &seances_file_name) {
    add_movies_to_the_database(movies_file_name);
    add_seances_to_the_database(seances_file_name);
}

void MovieAndSeanceService::add_movies_to_the_database(const std::string &file_name) const {
    json movies_data = Utils::get_data_from_json_file(file_name);

    // Add movies
    std::ranges::for_each(movies_data, [](const auto& movie_data) {
        // Create movie object
        Movie m = {0, movie_data["title"], movie_data["genre"], movie_data["author"]};

        // If there is no such movie, add it
        if(!MovieRepository::find_pos(m).has_value()) {
            MovieRepository::insert(m);
        }
    });
}

void MovieAndSeanceService::add_seances_to_the_database(const std::string &file_name) const {
    json seances_data = Utils::get_data_from_json_file(file_name);

    // Add seances
    std::ranges::for_each(seances_data, [](const auto& one_cinema) {
        // Check if given cinema exists
        auto cinema_id = CinemaRepository::find_pos(Cinema{0, one_cinema["cinema_name"], one_cinema["cinema_city"]});

        if(cinema_id.has_value()) {
            std::ranges::for_each(one_cinema["seances"], [](const auto& one_seance) {
                // Check if given movie exists
                auto movie_id = MovieRepository::find_pos_by_parameters(one_seance["movie_title"], one_seance["author"]);

                if(movie_id.has_value()) {
                    std::ranges::for_each(one_seance["details"], [&movie_id](const auto& one_detail) {
                        auto cinema_room_id = CinemaRoomRepository::find_pos_by_name(one_detail["cinema_room_name"]);

                        // Create seance object
                        Seance s{0, movie_id.value(), cinema_room_id.value(), one_detail["date_time"]};

                        // If there is no such seance, add it
                        if(!SeanceRepository::find_pos(s).has_value()) {
                            SeanceRepository::insert(s);
                        }
                    });
                }
            });
        }
    });
}
