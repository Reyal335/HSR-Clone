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
    int height, dwidth, mwidth, start_y, mstart_x, dstartx;
    height = 10;
    dwidth = 35;
    mwidth = 15;
    start_y = mstart_x = 0;
    dstartx = 20;
    

    WINDOW* menuwin = newwin(height, mwidth, start_y, mstart_x);
    WINDOW* descwin = newwin(height, dwidth, start_y, dstartx);
    refresh();

    box(menuwin, 0, 0);
    box(descwin, 0, 0);

    mvwprintw(descwin, 1, 1, "This is the description window");
    wrefresh(descwin);


    keypad(menuwin, true);

    std::array<std::string, 4> choices = {"Start Game", "Characters", "Gacha", "Settings"};
    int choice;
    int highlight = 0;
    bool running = true;

    while(running) {
        for (int i = 0; i < choices.size(); i++) {
            if (highlight == i)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, "%s", choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        wmove(menuwin, 6, 1);
        wrefresh(menuwin);
        choice = wgetch(menuwin);
        switch (choice) {
            case KEY_UP:
                highlight = std::clamp(highlight - 1, 0, static_cast<int>(choices.size()) - 1);
                wprintw(menuwin, "%s", choices[highlight].c_str());
                // wprintw(menuwin, "dfsf");
                break;
            case KEY_DOWN:
                highlight = std::clamp(highlight + 1, 0, static_cast<int>(choices.size()) - 1);
                wprintw(menuwin, "%s", choices[highlight].c_str());
                wclrtoeol(menuwin);
                // wprintw(menuwin, "dfsf");
                break;
            case '\n':
            case '\r':
            case KEY_ENTER:
                running = false;
                break;
        }


    }
    
    wrefresh(menuwin);

    getch();

    endwin();
}