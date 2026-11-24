#include <iostream> 
#include <ncurses\curses.h>
#include <windows.h>
#include "./helpers/magic_enum.hpp"
#include "characters/Stelle/Stelle.hpp"
#include "enemies/VoidRanger/VoidRanger.hpp"
#include "gameplay/Session.hpp"
#include <vector>
#include "entities/Character.hpp"

using namespace std;

int cursesWindow() {
    cout << "testing this c++ application" << endl;
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();

    int height = 10, width = 40, start_y = 0, start_x = 0;
    WINDOW* win = newwin(height, width, start_y, start_x);

    if (has_colors() == FALSE) {
        endwin();
        std::cout << "Your terminal doesn't support colours." << std::endl;
        return 1;
    }

    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Hello from ncurses!");
    mvwprintw(win, 3, 2, "Press any key to exit...");
    wrefresh(win);

    getch();
    std::cout << "hello reressr getch";
    mvwprintw(win, 3, 2, "Press any key to exit...");

    delwin(win);
    endwin();

    return 0;
}

int test() {


    std::unique_ptr<Stelle> stelle = std::make_unique<Stelle>();
    std::unique_ptr<VoidRanger> voidRanger = std::make_unique<VoidRanger>();
    // std::cout << "Stelle encounters a voidranger! " << std::endl;

    // std::cout << stelle->getName();
    // stelle->getHealth();
    // std::cout << voidRanger->getName();
    // voidRanger->getHealth();

    // stelle->performBasic(*voidRanger);
    // voidRanger->getHealth();
    std::vector<std::unique_ptr<Character>> characters;
    characters.push_back(std::move(stelle));

    Session session{std::move(characters)};
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
