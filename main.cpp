#include "service/cinema_management.hpp"
#include "service/movie_and_seance_management.hpp"
#include "service/user_management.hpp"

int main() {
    try {
        CinemaManagement cm{"cinemas.json"};
        MovieAndSeanceManagement masm{"movies.josn", "seances.json"};
        UserManagement am{"users.json"};
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