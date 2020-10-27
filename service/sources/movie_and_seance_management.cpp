//
// Created by Cezary Petryka on 25.10.2020.
//

#include "../movie_and_seance_management.hpp"

json MovieAndSeanceManagement::get_data_from_json_file(const std::string &file_name) const {
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

void MovieAndSeanceManagement::add_movies_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    Movie m;
    MovieRepository mr;

    std::for_each(data.begin(), data.end(), [&m, &mr](const auto& one_movie) {
        m = {0, one_movie["title"], one_movie["genre"], one_movie["author"]};

        if(mr.find_pos(m) == -1) {
            mr.insert(m);
        }
    });
}

void MovieAndSeanceManagement::add_seances_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_cinema) {
        // Check if given cinema exists
        CinemaRepository cr;
        auto cinema_id = cr.find_pos(Cinema{0, one_cinema["cinema_name"], one_cinema["cinema_city"]});

        if(cinema_id != -1) {
            std::for_each(one_cinema["seances"].begin(), one_cinema["seances"].end(), [&cinema_id](const auto& one_seance) {
                // Check if given movie exists
                MovieRepository mr;
                auto movie_id = mr.find_pos_by_title(one_seance["movie_title"]);

                if(movie_id != -1) {
                    std::for_each(one_seance["details"].begin(), one_seance["details"].end(), [&movie_id](const auto& one_detail) {
                        CinemaRoomRepository crr;
                        auto cinema_room_id = crr.find_pos_by_name(one_detail["cinema_room_name"]);

                        SeanceRepository sr;
                        Seance s{0, movie_id, cinema_room_id, one_detail["date_time"]};

                        if(sr.find_pos(s) == -1) {
                            sr.insert(s);
                        }
                    });
                }
            });
        }
    });
}

