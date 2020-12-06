#include "service/cinema_management.hpp"
#include "service/movie_and_seance_management.hpp"
#include "service/user_management.hpp"
#include "service/ticket_management.hpp"

int main() {
    try {
        /*CinemaManagement cm{"cinemas.json"};
        MovieAndSeanceManagement masm{"movies.json", "seances.json"};
        UserManagement am{"users.json"};*/

        TicketManagement tm;
        tm.buy_ticket();

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
 * wysylanie email
 * analiza stanu zarezerwowanych biletow co 15 minut
 * wlasciwa obluga klienta itp.
 * REFAKTORYZACJA
 * przy anulowaniu zamowienia lepiej ustawic state na "CANCELLED" czy po prostu usunac ??
 */

/*
* A. "AKCJA,WARSZAWA,21" -> szukam pasujace seansy -> zwraca liste pasujacych seansow
* B. user wybiera -> zwracam informacje o miejscach -> user wybiera miejsca do zarezerwowania
* C. rezerwacja/kupno -> wyliczenie ceny + zapisanie do db + email
* D. kiedy rezerwacja przydzielic unikalne oznaczenie, ktore user moze wykorzystac
*    analiza stanu zarezerwowanych biletow co 15 minut
* */