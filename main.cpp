#include "repository/cinema_repository.hpp"
#include "repository/cinema_room_repository.hpp"
#include "repository/seat_repository.hpp"
#include "repository/movie_repository.hpp"
#include "repository/seance_repository.hpp"
#include "repository/user_repository.hpp"
#include "repository/customer_repository.hpp"
#include "repository/ticket_repository.hpp"
#include "service/cinema_management.hpp"

int main() {
    try {
        CinemaManagement cm{"cinemas.json"};
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/*
 * Dostaje plik json i na jego podstawie musze stworzyc tabele: cinemas, cinema_rooms, seats
 *
 * JSON     ->      Cinema      ->     CinemaRepository
 *          ->      CinemaRoom  ->     CinemaRoomRepository
 *          ->      Seats       ->     SeatRepository
 * */