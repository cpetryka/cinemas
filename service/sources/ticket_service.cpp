//
// Created by Cezary Petryka on 03.11.2020.
//

#include "../ticket_service.hpp"

std::string TicketService::get_user_preferences() {
    std::cout << "Specify your preferences (movie_genre, city, date, time):" << std::endl;
    std::string user_preferences;
    std::getline(std::cin, user_preferences);
    system("cls");

    if(user_preferences.empty()) {
        std::cout << "== ERROR - Incorrect input. Try again later. ==" << std::endl;
    }

    return user_preferences;
}

std::string TicketService::convert_available_seances_to_string(
        const std::vector<std::unique_ptr<SeanceWithMovie>> &available_seances) {
    std::stringstream ss;

    for(auto i = 0; i < available_seances.size(); ++i) {
        ss << i + 1 << " --> " << *available_seances.at(i) << std::endl;
    }

    return ss.str();
}

int TicketService::choose_seance_number(const int seances_number) {
    auto user_choice = 0;

    do {
        std::cout << "Which seance do you choose?" << std::endl;
        std::cin >> user_choice; std::cin.get();
        --user_choice; // because user_choice is in range [1, seances_number] and we want to have it in range [0, seances_number - 1]
    } while(user_choice < 0 || user_choice > seances_number - 1);

    return user_choice;
}

std::optional<std::unique_ptr<SeanceWithMovie>> TicketService::choose_seance(const std::string& user_prefs_str) {
    auto user_prefs = Utils::convert_string_to_vector(user_prefs_str, ',');

    if(user_prefs.size() != 4) {
        throw std::invalid_argument("Incorrect input! Try again later!");
    }

    // Find available seances
    auto available_seances = SeanceRepository::find_all_by_parameters(user_prefs.at(0), user_prefs.at(1),
                                                                      user_prefs.at(2), user_prefs.at(3));

    // If there are no available seances, return std::nullopt
    if(available_seances.empty()) {
        return std::nullopt;
    }

    // Shows available seances
    std::cout << convert_available_seances_to_string(available_seances) << std::endl;

    // Let user choose seance
    auto user_choice = choose_seance_number(available_seances.size());

    return std::make_unique<SeanceWithMovie>(*available_seances.at(user_choice));
}

std::vector<std::unique_ptr<Seat>> TicketService::find_available_seats(const int seance_id, const int room_id, const int rows, const int places) {
    // Generate a vector with seats
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = CinemaRoomRepository::find_all_seats_in_given_room(room_id, rows, places);

    // Check which places are not available
    std::vector<int> reserved_seats = TicketRepository::find_reserved_seats(seance_id);

    // Take into account the occupied places in the first vector
    std::ranges::for_each(reserved_seats, [&seats_in_cinema_room](const auto& reserved_seat) {
        auto found_element = std::ranges::find_if(seats_in_cinema_room, [&reserved_seat](const auto& one_seat) {
            return one_seat->id == reserved_seat;
        });

        if(found_element != seats_in_cinema_room.end()) {
            (*found_element)->id = -1;
        }
    });

    return seats_in_cinema_room;
}

std::string TicketService::convert_available_places_to_string(const std::vector<std::unique_ptr<Seat>> &seats_in_cinema_room,
                                                              const int places) {
    std::stringstream ss;

    for(auto i = 0; i < seats_in_cinema_room.size(); ++i) {
        if(seats_in_cinema_room.at(i)->id != -1) {
            ss << i + 1 << "\t";
        }
        else {
            ss << "----" << "\t";
        }

        if((i + 1) % places == 0) {
            ss << std::endl;
        }
    }

    return ss.str();
}

bool TicketService::check_if_all_chosen_places_are_available(std::vector<int>& chosen_places,
                                                             const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) {
    return std::ranges::all_of(chosen_places, [&seats_in_cinema_room](const auto& one_place) {
        return seats_in_cinema_room.at(one_place)->id != -1;
    });
}

std::vector<int>
TicketService::get_selected_places(const std::vector<std::unique_ptr<Seat>> &seats_in_cinema_room) {
    std::string user_choice;
    std::vector<int> chosen_places;

    while(true) {
        std::cout << "Enter the desired places (separate them by a comma):" << std::endl;
        std::getline(std::cin, user_choice);
        system("cls");

        if(!std::regex_match(user_choice, std::regex("^[0-9]+(,[0-9]+)*$"))) {
            continue;
        }

        auto temp = Utils::convert_string_to_vector(user_choice, ',');
        std::ranges::transform(temp, std::back_inserter(chosen_places), [](const auto& one_string) {
            return std::stoi(one_string) - 1;
        });

        if(!check_if_all_chosen_places_are_available(chosen_places, seats_in_cinema_room)) {
            std::cout << "Some of the selected places are not available! Try again!" << std::endl;
            chosen_places.clear();
            continue;
        }

        for (auto& chosen_seat : chosen_places) {
            chosen_seat = seats_in_cinema_room.at(chosen_seat)->id;
        }

        break;
    }

    return chosen_places;
}

std::vector<int> TicketService::choose_seats(const int seance_id, const int cinema_room_id) {
    auto cinema_room_tmp = CinemaRoomRepository::find_by_id(cinema_room_id);

    // Find all available seats
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = find_available_seats(seance_id, cinema_room_id,
                                                                                   cinema_room_tmp.value()->rows,
                                                                                   cinema_room_tmp.value()->places);

    // Shows information about places
    std::cout << convert_available_places_to_string(seats_in_cinema_room, cinema_room_tmp.value()->places) << std::endl;

    // Seat choice
    auto chosen_places = get_selected_places(seats_in_cinema_room);

    return chosen_places;
}

std::string TicketService::choose_reservation_or_order() {
    auto choice = 0;

    do {
        std::cout << "Do you want to reserve or buy the ticket (1 - reserve, 2 - buy)?" << std::endl;
        std::cin >> choice; std::cin.get();
        system("cls");
    } while(choice != 1 && choice != 2);

    return (choice == 1) ? "RESERVED" : "ORDERED";
}

void TicketService::buy_ticket() {
    // Get user preferences (city, genre, date)
    std::string user_preferences = get_user_preferences();

    // Choose seance, seats and whether to reserve or buy the tickets
    auto chosen_seance = choose_seance(user_preferences);

    if(!chosen_seance.has_value()) {
        std::cout << "== There are no seances that meet your requirements. ==" << std::endl;
        std::this_thread::sleep_for(3000ms);
        system("cls");
        return;
    }

    system("cls");

    auto chosen_seats = choose_seats(chosen_seance.value()->seance_id,
                                     chosen_seance.value()->seance_cinema_room_id);
    auto state = choose_reservation_or_order();

    // User signs in, in order to add tickets to his/her account
    auto customer_id = UserService::sign_in();

    // Add tickets to the database
    for(const int& chosen_seat_id : chosen_seats) {
        TicketRepository::insert(Ticket{0, customer_id.value(), chosen_seance.value()->seance_id, chosen_seat_id, 20, state});
    }

    // Print final information
    if(state == "RESERVED") {
        std::cout << "Your ticket ID: ..." << std::endl;
        std::cout << "You can use this ID to pay for or cancel your tickets." << std::endl;
        std::this_thread::sleep_for(3000ms);
        system("cls");
    }

    std::cout << "Thank you for buying/reserving the tickets!" << std::endl;
    std::this_thread::sleep_for(2000ms);
    system("cls");
}

void TicketService::manage_ticket(const int ticket_id) {
    auto ticket_tmp = TicketRepository::find_by_id(ticket_id);

    if(!ticket_tmp.has_value()) {
        std::cout << "There is no ticket with this ID!" << std::endl;
        std::this_thread::sleep_for(2000ms);
        system("cls");
        return;
    }

    while(true) {
        std::cout << "=======================" << std::endl;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - pay for the ticket" << std::endl;
        std::cout << "2 - cancel" << std::endl;
        std::cout << "9 - return to the main menu" << std::endl;

        std::cout << std::endl << "Your choice: ";
        auto user_choice = 0;
        std::cin >> user_choice; std::cin.get();
        system("cls");

        switch (user_choice) {
            case 1:
                ticket_tmp.value()->state = TicketState::from_string("ORDERED");
                TicketRepository::update(ticket_id, *ticket_tmp.value());

                system("cls");
                std::cout << "Thank you for paying for the ticket!" << std::endl;
                std::this_thread::sleep_for(2000ms);
                system("cls");

                return;
            case 2:
                TicketRepository::cancel_ticket_by_id(ticket_id);

                system("cls");
                std::cout << "Ticket cancellation successful!" << std::endl;
                std::this_thread::sleep_for(2000ms);
                system("cls");
                return;
            case 9:
                return;
            default:
                std::cout << "== ERROR - Incorrect input. Try again later. ==" << std::endl;
        }
    }
}
