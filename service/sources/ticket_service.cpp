//
// Created by Cezary Petryka on 03.11.2020.
//

#include "../ticket_service.hpp"

std::string TicketService::get_user_preferences() const {
    std::cout << "Specify your preferences (movie_genre, city, date, time): " << std::endl;
    std::string user_preferences;
    std::getline(std::cin, user_preferences);
    system("cls");

    if(user_preferences.empty()) {
        std::cout << "== ERROR - Incorrect input. Try again later. ==" << std::endl;
    }

    return user_preferences;
}

std::string TicketService::generate_available_seance_info(
        const std::vector<std::unique_ptr<SeanceWithMovie>> &available_seances) const {
    std::stringstream ss;

    for(auto i = 0; i < available_seances.size(); ++i) {
        ss << i + 1 << " --> " << *available_seances.at(i) << std::endl;
    }

    return ss.str();
}

int TicketService::get_selected_seance(const int seance_number) const {
    auto user_choice = 0;

    do {
        std::cout << "Which seance do you choose?" << std::endl;
        std::cin >> user_choice; std::cin.get();
        --user_choice;
        system("cls");
    } while(user_choice < 0 || user_choice > seance_number - 1);

    return user_choice;
}

std::optional<std::unique_ptr<SeanceWithMovie>> TicketService::seance_choice(const std::string& user_prefs_str) const {
    auto user_prefs = Utils::convert_string_to_vector(user_prefs_str, ',');

    if(user_prefs.size() != 4) {
        throw std::runtime_error("Incorrect input! Try again later!");
    }

    auto available_seances = SeanceRepository::find_by_parameters(user_prefs.at(0), user_prefs.at(1), user_prefs.at(2), user_prefs.at(3));

    if(available_seances.size() == 0) {
        throw std::runtime_error("Incorrect input! There is no seance with such data. Try again later!");
    }

    // Shows info about available seances
    std::cout << generate_available_seance_info(available_seances) << std::endl;

    // Get information about chosen seance
    auto user_choice = get_selected_seance(available_seances.size());

    return std::make_unique<SeanceWithMovie>(*available_seances.at(user_choice));
}

std::vector<std::unique_ptr<Seat>> TicketService::find_available_places(const int seance_id, const int room_id, const int rows, const int places) const {
    // Generate a vector with seats
    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = CinemaRoomRepository::find_all_seats_in_given_room(room_id, rows, places);

    // Check which places are not available
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

bool TicketService::check_if_places_are_available_and_conversion(std::vector<int>& chosen_places,
                                                                 const std::vector<std::unique_ptr<Seat>>& seats_in_cinema_room) const {
    for(auto& one_of_chosen_places : chosen_places) {
        if(seats_in_cinema_room.at(one_of_chosen_places)->id != -1) {
            one_of_chosen_places = seats_in_cinema_room.at(one_of_chosen_places)->id;
        }
        else {
            return false;
        }
    }

    return true;
}

std::string
TicketService::generate_available_places_info(const std::vector<std::unique_ptr<Seat>> &seats_in_cinema_room,
                                              const int places) const {
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

std::vector<int>
TicketService::get_selected_places(const std::vector<std::unique_ptr<Seat>> &seats_in_cinema_room) const {
    std::string user_choice;
    std::vector<int> chosen_places;

    while(true) {
        std::cout << "Enter the desired places (separate them by a comma):" << std::endl;
        std::getline(std::cin, user_choice);
        system("cls");

        auto tmp = Utils::convert_string_to_vector(user_choice, ',');
        chosen_places.resize(tmp.size());
        std::transform(tmp.begin(), tmp.end(), chosen_places.begin(), [](const auto& one_string) {
            return std::stoi(one_string) - 1;
        });

        if(check_if_places_are_available_and_conversion(chosen_places, seats_in_cinema_room)) {
            break;
        }
        else {
            std::cout << "== ERROR! - Incorrect input! Try again. ==" << std::endl;
        }
    }

    return chosen_places;
}


std::vector<int> TicketService::seat_choice(const int seance_id, const int cinema_room_id) const {
    auto cinema_room_tmp = CinemaRoomRepository::find_by_id(cinema_room_id);

    std::vector<std::unique_ptr<Seat>> seats_in_cinema_room = find_available_places(seance_id, cinema_room_id, cinema_room_tmp.value()->rows, cinema_room_tmp.value()->places);

    // Shows information about places
    std::cout << generate_available_places_info(seats_in_cinema_room, cinema_room_tmp.value()->places) << std::endl;

    // Seat choice
    auto chosen_places = get_selected_places(seats_in_cinema_room);

    return chosen_places;
}

std::string TicketService::reservation_or_order() const {
    auto choice = 0;

    do {
        std::cout << "Do you want to reserve or buy (1 - reserve, 2 - buy)?:" << std::endl;
        std::cin >> choice; std::cin.get();
        system("cls");
    } while(choice != 1 && choice != 2);

    return (choice == 1) ? "RESERVED" : "ORDERED";
}

void TicketService::buy_ticket() const {
    std::string user_preferences = get_user_preferences();

    auto chosen_seance = seance_choice(user_preferences);
    auto chosen_seats = seat_choice(chosen_seance.value()->seance_id,
                                      chosen_seance.value()->seance_cinema_room_id);
    auto state = reservation_or_order();

    auto customer_id = UserService::sign_in();

    for(int & chosen_seat_id : chosen_seats) {
        TicketRepository::insert(Ticket{0, customer_id, chosen_seance.value()->seance_id, chosen_seat_id, 20, state});
    }

    if(state == "RESERVED") {
        std::cout << "Your ticket ID: ..." << std::endl;
        std::cout << "You can use this ID to pay for or cancel your order." << std::endl;
        std::this_thread::sleep_for(3000ms);
        system("cls");
    }

    std::cout << "Thank you for buying/reserving the tickets!" << std::endl;
    std::this_thread::sleep_for(2000ms);
    system("cls");
}

void TicketService::manage_reserved_seat(const int ticket_id) const {
    auto ticket_tmp = TicketRepository::find_by_id(ticket_id);
    auto user_choice = 0;

    if(ticket_tmp.has_value()) {
        if(ticket_tmp.value()->state != TicketState::from_string("RESERVED")) {
            std::cout << "This ticket is not reserved!" << std::endl;
            std::this_thread::sleep_for(2000ms);
            system("cls");
            return;
        }

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - pay the ticket" << std::endl;
        std::cout << "2 - cancel" << std::endl;

        std::cout << std::endl << "Your choice:" << std::endl;
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

                break;
            case 2:
                TicketRepository::cancel_ticket_by_id(ticket_id);

                system("cls");
                std::cout << "Ticket cancellation successful!" << std::endl;
                std::this_thread::sleep_for(2000ms);
                system("cls");
                break;
            default:
                std::cout << "== ERROR - Incorrect input. Try again later. ==" << std::endl;
        }
    }
}
