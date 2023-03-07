//
// Created by Cezary Petryka on 25.10.2020.
//

#include "../movie_and_seance_manager.hpp"

json MovieAndSeanceManager::get_data_from_json_file(const std::string &file_name) const {
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

MovieAndSeanceManager::MovieAndSeanceManager(const std::string &movies_file_name,
                                             const std::string &seances_file_name) {
    add_movies_to_the_database(movies_file_name);
    add_seances_to_the_database(seances_file_name);
}

void MovieAndSeanceManager::add_movies_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_movie) {
        Movie m = {0, one_movie["title"], one_movie["genre"], one_movie["author"]};

        if(!MovieRepository::find_pos(m).has_value()) {
            MovieRepository mr;
            mr.insert(m);
        }
    });
}

void MovieAndSeanceManager::add_seances_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_cinema) {
        // Check if given cinema exists
        auto cinema_id = CinemaRepository::find_pos(Cinema{0, one_cinema["cinema_name"], one_cinema["cinema_city"]});

        if(cinema_id.has_value()) {
            std::for_each(one_cinema["seances"].begin(), one_cinema["seances"].end(), [](const auto& one_seance) {
                // Check if given movie exists
                auto movie_id = MovieRepository::find_pos_by_parameters(one_seance["movie_title"], one_seance["author"]);

                if(movie_id.has_value()) {
                    std::for_each(one_seance["details"].begin(), one_seance["details"].end(), [&movie_id](const auto& one_detail) {
                        CinemaRoomRepository crr;
                        auto cinema_room_id = crr.find_pos_by_name(one_detail["cinema_room_name"]);

                        Seance s{0, movie_id.value(), cinema_room_id.value(), one_detail["date_time"]};

                        if(!SeanceRepository::find_pos(s).has_value()) {
                            SeanceRepository sr;
                            sr.insert(s);
                        }
                    });
                }
            });
        }
    });
}
