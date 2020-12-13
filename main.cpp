#include "service/cinema_management.hpp"
#include "service/movie_and_seance_management.hpp"
#include "service/user_management.hpp"
#include "service/ticket_management.hpp"

void menu() {
    auto user_choice = 0;

    while(true) {
        std::cout << "==================== MENU ====================" << std::endl;
        std::cout << "== 1. BUY TICKETS" << std::endl;
        std::cout << "== 2. MANAGE RESERVED TICKETS" << std::endl;
        std::cout << "== 3. MANAGE YOUR ACCOUNT" << std::endl;
        std::cout << "== 9. LOG OUT" << std::endl;
        std::cout << "==================== MENU ====================" << std::endl;

        std::cout << "Your choice: " << std::endl;
        std::cin >> user_choice; std::cin.get();

        TicketManagement tm;
        auto ticket_id_tmp = 0;

        switch (user_choice) {
            case 1:
                tm.buy_ticket();
                break;
            case 2:
                std::cout << "Enter your ticket id: " << std::endl;
                std::cin >> ticket_id_tmp; std::cin.get();
                tm.manage_reserved_seat(ticket_id_tmp);
                break;
            case 3:
                break;
            case 9:
                return;
            default:
                std::cout << "There is no such option! Try again." << std::endl;
        }
    }
}

int main() {
    try {
        /*CinemaManagement cm{"cinemas.json"};
        MovieAndSeanceManagement masm{"movies.json", "seances.json"};
        UserManagement am{"users.json"};*/

        menu();

        // "ACTION", "WARSAW", "2020-11-10", "14"
        // ACTION,WARSAW,2020-11-10,14
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/*
 * user -> role -> mozna zrobic enum / walidacje
 * customer -> gender -> mozna zrobic enum / walidacje
 * ticket -> status -> mozna zrobic enum / walidacje
 * seance -> date_time -> teraz jest jako napis, mozna zrobic jako 'datetime',
 *                        ale i tak bedzie przekonwertowany na typ 'numeric'
 *
 * wysylanie email
 * analiza stanu zarezerwowanych biletow co 15 minut
 * wlasciwa obluga klienta itp.
 * obsluga bledow
 * REFAKTORYZACJA
 */

/*
* A. "AKCJA,WARSZAWA,21" -> szukam pasujace seansy -> zwraca liste pasujacych seansow
* B. user wybiera -> zwracam informacje o miejscach -> user wybiera miejsca do zarezerwowania
* C. rezerwacja/kupno -> wyliczenie ceny + zapisanie do db + email
* D. kiedy rezerwacja przydzielic unikalne oznaczenie, ktore user moze wykorzystac
*    analiza stanu zarezerwowanych biletow co 15 minut
* */