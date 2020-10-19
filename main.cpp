#include "repository/cinema_repository.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    try {
        Cinema c{0, "CINEMA CITY", "CRACOW"};
        CinemaRepository cinema_repository;
        // cinema_repository.insert(c);
        // cinema_repository.update(1, c);
        // cinema_repository.remove(2);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}