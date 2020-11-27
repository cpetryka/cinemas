//
// Created by Cezary Petryka on 03.11.2020.
//

#include "../ticket_management.hpp"

std::vector<std::string> TicketManagement::convert_string_to_vector(const std::string& str, const char separator) const {
    std::vector<std::string> strings;
    std::string one_string;
    std::stringstream ss(str);

    while(getline(ss, one_string, separator)) {
        strings.emplace_back(one_string);
    }

    return strings;
}

std::optional<std::unique_ptr<SeanceWithMovie>> TicketManagement::seance_choice(const std::string& user_prefs_str) const {
    auto user_prefs = convert_string_to_vector(user_prefs_str, ',');
    auto available_seances = SeanceRepository::find_by_parameters(user_prefs.at(0), user_prefs.at(1), user_prefs.at(2), user_prefs.at(3));
    auto user_choice = 0;

    if(available_seances.size() == 0) {
        return std::nullopt;
    }

    for(auto i = 0; i < available_seances.size(); ++i) {
        std::cout << i << " -> " << *available_seances.at(i) << std::endl;
    }

    do {
        std::cout << "Which seance do you choose?" << std::endl;
        std::cin >> user_choice; std::cin.get();
    } while(user_choice < 0 || user_choice > available_seances.size() - 1);

    return std::make_unique<SeanceWithMovie>(*available_seances.at(user_choice));
}

int TicketManagement::seat_choice(const int seance_id, const int cinema_room_id) const {
    // Pobieram informacje o wszystkich miejscach w danej sali
    CinemaRoomRepository crr;
    auto cinema_room_tmp = crr.find_by_id(cinema_room_id);

    // Generuje wektor z miejscami
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room;
    SeatRepository sr;
    int counter = 0;

    for(auto i = 0; i < cinema_room_tmp.value()->rows; ++i) {
        for(auto j = 0; j < cinema_room_tmp.value()->places; ++j) {
            seats_in_cinema_room.emplace_back(std::make_unique<Seat>(*sr.find_by_parameters(cinema_room_id, i + 1, j + 1).value()));
        }
    }

    // Sprawdzam ktore miejsca sa zajete
    std::vector<int> reserved_seats = TicketRepository::find_reserved_seats(seance_id);

    // Uwzgledniam zajete miejsca w pierwszym wektorze
    std::for_each(reserved_seats.begin(), reserved_seats.end(), [&seats_in_cinema_room](const auto& reserved_seat) {
        std::for_each(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [&reserved_seat](const auto& one_seat) {
            if(one_seat->id == reserved_seat) {
                one_seat->id = -1;
            }
        });
    });

    std::for_each(reserved_seats.begin(), reserved_seats.end(), [&seats_in_cinema_room](const auto& reserved_seat) {
        auto found_element = std::find_if(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [&reserved_seat](const auto& one_seat) {
            return one_seat->id == reserved_seat;
        });

        if(found_element != seats_in_cinema_room.end()) {
            std::cout << "FOUND!" << std::endl;
        }
    });

    std::for_each(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [](const auto& one_seat) {
            if(one_seat->id != -1) {
                std::cout << one_seat->id << "\t";
            }
            else {
                std::cout << "XX" << "\t";
            }
    });

    // SOLUTION 2
    /*// Pobieram informacje o wszystkich miejscach w danej sali
    CinemaRoomRepository crr;
    auto cinema_room_tmp = crr.find_by_id(cinema_room_id);

    // Generuje wektor z miejscami
    std::vector<std::vector<std::unique_ptr<Seat>>> seats_in_cinema_room (cinema_room_tmp.value()->rows);
    SeatRepository sr;
    int counter = 0;

    for(auto i = 0; i < cinema_room_tmp.value()->rows; ++i) {
        for(auto j = 0; j < cinema_room_tmp.value()->places; ++j) {
            seats_in_cinema_room.at(i).emplace_back(std::make_unique<Seat>(*sr.find_by_parameters(cinema_room_id, i + 1, j + 1).value()));
        }
    }

    // Sprawdzam ktore miejsca sa zajete
    std::vector<int> reserved_seats = TicketRepository::find_reserved_seats(seance_id);

    // Uwzgledniam zajete miejsca w pierwszym wektorze
    std::for_each(reserved_seats.begin(), reserved_seats.end(), [&seats_in_cinema_room](const auto& reserved_seat) {
        std::for_each(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [&reserved_seat](const auto& one_row) {
            std::for_each(one_row.begin(), one_row.end(), [&reserved_seat](const auto& one_seat) {
                if(one_seat->id == reserved_seat) {
                    one_seat->id = -1;
                }
            });
        });
    });

    std::for_each(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [](const auto& one_row) {
        std::for_each(one_row.begin(), one_row.end(), [](const auto& one_seat) {
            if(one_seat->id != -1) {
                std::cout << one_seat->id << "\t";
            }
            else {
                std::cout << "XX" << "\t";
            }
        });

        std::cout << std::endl;
    });*/

    // SOLUTION 1
    /*std::for_each(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [&reserved_seats](const auto& one_row){

        for(const auto& value : reserved_seats) {

            auto found_element = std::find_if(one_row.begin(), one_row.end(), [&value](const auto& one_elem){
                std::cout << "=> " << one_elem.value()->id << std::endl;
                return one_elem.value()->id == value;
            });

            // std::cout << std::type_info(found_element).name() << std::endl;
            // std::cout << *(*(*found_element).value()) << std::end;
            // std::cout << *(*found_element).value()->id << std::endl;
            // std::cout << *(*found_element.value())->id << std::endl;


            do {

                //found_element = std::find_if(one_row.begin(), one_row.end(), [&value](const auto& one_elem){
                //    return one_elem == value;
                //});
            } while(found_element != one_row.end());
        }
    });*/

    return 0;
}

void TicketManagement::buy_ticket() const {
    std::cout << "Specify your preferences (movie_genre, city, date, time): " << std::endl;
    std::string user_preferences;
    std::getline(std::cin, user_preferences);

    auto chosen_seance = seance_choice(user_preferences);
    auto chosen_seat_id = seat_choice(chosen_seance.value()->seance_id,
                                      chosen_seance.value()->seance_cinema_room_id);
}