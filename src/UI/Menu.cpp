#include "Menu.hpp"
#include <ncurses/curses.h>
#include <string>
#include <array>
#include <algorithm>

void Menu::displayMenu() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int height, width, start_y, start_x;
    height = 10;
    width = 30;
    start_y = start_x = 0;
    

    WINDOW* menuwin = newwin(height, width, start_y, start_x);
    refresh();

    box(menuwin, 0, 0);



    keypad(menuwin, true);

    std::array<std::string, 4> choices = {"Start Game", "Characters", "Gacha", "Settings"};
    int choice;
    int highlight = 0;

    while(1) {
        for (int i = 0; i < choices.size(); i++) {
            if (highlight == i)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        wmove(menuwin, 6, 1);
        wrefresh(menuwin);
        choice = wgetch(menuwin);
        
        switch (choice) {
            case KEY_UP:
                highlight = std::clamp(highlight - 1, 0, static_cast<int>(choices.size()) - 1);
                break;
            case KEY_DOWN:
                highlight = std::clamp(highlight + 1, 0, static_cast<int>(choices.size()) - 1);
                break;
            case 3:
                choice = 2;
                break;
            case 4:
                choice = 3;
                break;
        }


    }
    


    getch();

    endwin();
}