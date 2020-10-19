#include "repository/cinema_room_repository.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    try {
        // Cinema c{0, "CINEMA CITY", "CRACOW"};
        // CinemaRepository cinema_repository;
        // cinema_repository.insert(c);
        // cinema_repository.update(1, c);
        // cinema_repository.remove(2);

        // CinemaRoom cr{0, "THE BEST ONE", 1, 40, 20};
        // CinemaRoomRepository crr;
        // crr.insert(cr);
        // crr.update(2, cr);
        // crr.remove(1);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}