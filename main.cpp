#include "service/cinema_management.hpp"
#include "service/movie_and_seance_management.hpp"
#include "service/user_management.hpp"

int main() {
    try {
        CinemaManagement cm{"cinemas.json"};
        MovieAndSeanceManagement masm{"movies.json", "seances.json"};
        UserManagement am{"users.json"};

        auto ss = SeanceRepository::find_by_parameters("ACTION", "WARSAW", "2020-11-10", "14");

        for(const auto& one_seance : ss) {
            std::cout << one_seance->movie_title << " " << one_seance->seance_date_time << std::endl;
        }
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
 */

/*
* A. "AKCJA,WARSZAWA,21" -> szukam pasujace seansy -> zwraca liste pasujacych seansow
* B. user wybiera -> zwracam informacje o miejscach (tablica dwuwymiarowa) ->
*    user wybiera miejsca do zarezerwowania + rezerwacja/kupno
* C. analiza miejsca (ok, czy zajete) -> wyliczenie ceny + zapisanie do db + email
* D. kiedy rezerwacja przydzielic unikalne oznaczenie, ktore user moze wykorzystac
*    analiza stanu zarezerwowanych biletow co 15 minut
* */