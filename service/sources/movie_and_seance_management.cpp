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
        // Add cinema
        m = {0, one_movie["title"], one_movie["genre"], one_movie["author"]};

        /*if(mr.find_pos(m) == -1) {
            mr.insert(m);
        }*/
    });
}

