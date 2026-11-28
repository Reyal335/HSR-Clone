#include <iostream> 
#include <ncurses\curses.h>
#include <windows.h>
#include "./helpers/magic_enum.hpp"
#include "characters/Stelle/Stelle.hpp"
#include "enemies/VoidRanger/VoidRanger.hpp"
#include "gameplay/Session.hpp"
#include <vector>
#include "entities/Character.hpp"
#include "UI/Menu.hpp"

using namespace std;

int cursesWindow() {

    Menu menu{};
    menu.displayMenu();
    return 0;
}

int test() {


    std::unique_ptr<Stelle> stelle = std::make_unique<Stelle>(1);
    // std::cout << "Stelle encounters a voidranger! " << std::endl;

    // std::cout << stelle->getName();
    // stelle->getHealth();
    // std::cout << voidRanger->getName();
    // voidRanger->getHealth();

    // stelle->performBasic(*voidRanger);
    // voidRanger->getHealth();
    std::vector<std::unique_ptr<Character>> roster;
    roster.push_back(std::move(stelle));

    Session session{std::move(roster)};
    session.startSession(1, 2);

    return 0;
}


int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    char input;

    std::cout << "Select Mode: " << std::endl;
    std::cout << "[T] CLI test" << std::endl;
    std::cout << "[N] NCurses" << std::endl;
    std::cin >> input;

    if (input == 't') {
        test();
    } else {
        cursesWindow();
    }

    return 0;
}
