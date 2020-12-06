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

std::vector<std::unique_ptr<Seat>> TicketManagement::find_available_places(const int seance_id, const int room_id, const int rows, const int places) const {
    // Generuje wektor z miejscami
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = CinemaRoomRepository::find_all_seats_in_given_room(room_id, rows, places);

    // Sprawdzam ktore miejsca sa zajete
    std::vector<int> reserved_seats = TicketRepository::find_reserved_seats(seance_id);

    // Uwzgledniam zajete miejsca w pierwszym wektorze
    std::for_each(reserved_seats.begin(), reserved_seats.end(), [&seats_in_cinema_room](const auto& reserved_seat) {
        auto found_element = std::find_if(seats_in_cinema_room.begin(), seats_in_cinema_room.end(), [&reserved_seat](const auto& one_seat) {
            return one_seat->id == reserved_seat;
        });

        if(found_element != seats_in_cinema_room.end()) {
            (*found_element)->id = -1;
        }
    });

    return seats_in_cinema_room;
}

int TicketManagement::seat_choice(const int seance_id, const int cinema_room_id) const {
    CinemaRoomRepository crr;
    auto cinema_room_tmp = crr.find_by_id(cinema_room_id);

    // Pobiera informacje o dostepnych miejscach
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = find_available_places(seance_id, cinema_room_id, cinema_room_tmp.value()->rows, cinema_room_tmp.value()->places);

    // Wyswietlam informacje o miejscach
    for(auto i = 0; i < seats_in_cinema_room.size(); ++i) {
        if(seats_in_cinema_room.at(i)->id != -1) {
            std::cout << i + 1 << "\t";
        }
        else {
            std::cout << "----" << "\t";
        }

        if((i + 1) % cinema_room_tmp.value()->places == 0) {
            std::cout << std::endl;
        }
    }

    // Wybor miejsca
    auto user_choice = 0;

    while(true) {
        std::cout << "I've chosen place number:" << std::endl;
        std::cin >> user_choice; std::cin.get();

        if(seats_in_cinema_room.at(user_choice - 1)->id != -1) {
            user_choice = seats_in_cinema_room.at(user_choice)->id;
            break;
        }
    }

    return user_choice;
}

std::string TicketManagement::reservation_or_order() const {
    auto choice = 0;

    do {
        std::cout << "Do you want to reserve or buy (1 - reserve, 2 - buy)?:" << std::endl;
        std::cin >> choice; std::cin.get();
    } while(choice != 1 && choice != 2);

    return (choice == 1) ? "RESERVED" : "ORDERED";
}


void TicketManagement::buy_ticket() const {
    std::cout << "Specify your preferences (movie_genre, city, date, time): " << std::endl;
    std::string user_preferences;
    std::getline(std::cin, user_preferences);

    auto chosen_seance = seance_choice(user_preferences);
    auto chosen_seat_id = seat_choice(chosen_seance.value()->seance_id,
                                      chosen_seance.value()->seance_cinema_room_id);
    auto state = reservation_or_order();
}