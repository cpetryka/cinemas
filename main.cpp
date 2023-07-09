#include "service/cinema_service.hpp"
#include "service/movie_and_seance_service.hpp"
#include "service/user_service.hpp"
#include "service/ticket_service.hpp"
#include "utils/ticket_status_analyser.hpp"

void menu() {
    auto user_choice = 0;

    while(true) {
        std::cout << "==================== MENU ====================" << std::endl;
        std::cout << "== 1. BUY TICKETS" << std::endl;
        std::cout << "== 2. MANAGE YOUR TICKET" << std::endl;
        std::cout << "== 3. MANAGE YOUR ACCOUNT" << std::endl;
        std::cout << "== 9. EXIT" << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << "Your choice: " << std::endl;
        std::cin >> user_choice; std::cin.get();
        system("cls");

        TicketService tm;

        switch (user_choice) {
            case 1:
                tm.buy_ticket();
                break;
            case 2:
                {
                    std::cout << "Enter your ticket id: " << std::endl;
                    auto ticket_id = 0;
                    std::cin >> ticket_id; std::cin.get();
                    system("cls");

                    TicketService::manage_ticket(ticket_id);
                }
                break;
            case 3:
                UserService::manage_account();
                break;
            case 9:
                return;
            default:
                std::cout << "There is no such option! Try again." << std::endl;
        }
    }
}

int main() {
    // Creats database - tables for cinemas, movies, seances, users, tickets etc.
    CinemaService cm{"../data/cinemas.json"};
    MovieAndSeanceService masm{"../data/movies.json", "../data/seances.json"};
    UserService am{"../data/users.json"};

    CallBackTimer cbt;
    cbt.start(900000, TicketStatusAnalyser::cancel_unpaid_tickets);

    menu();

    if(cbt.is_running()) {
        cbt.stop();
    }

    return 0;
}