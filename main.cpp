#include "repository/cinema_repository.hpp"
#include "repository/cinema_room_repository.hpp"
#include "repository/seat_repository.hpp"

int main() {
    try {
         /*Cinema c{0, "MULTIKINO", "WARSOW"};
         CinemaRepository cinema_repository;
         cinema_repository.insert(c);
         cinema_repository.update(1, c);
         cinema_repository.remove(2);*/

         /*CinemaRoom cr{0, "THE BEST ONE", 2, 30, 40};
         CinemaRoomRepository crr;
         crr.insert(cr);
         crr.update(2, cr);
         crr.remove(1);*/

        /*Seat s{0, 1, 2, 4};
        Seat s2{0, 2, 3, 10};
        SeatRepository sr;
        sr.insert(s);
        sr.update(2, s2);
        sr.remove(5);*/
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}