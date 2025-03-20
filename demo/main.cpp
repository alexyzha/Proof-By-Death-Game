#include <ncurses.h>
#include "util.h"
#include "character.h"

int main(int argc, char* argv[]) {
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_RED);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);

    int height, width;
    getmaxyx(stdscr, height, width);

    int start_x = (width - 20) / 2;
    int y = height / 2;
    for(int i = 0; i < 8; ++i) {
        attron(COLOR_PAIR(i + 1));
        mvprintw(y, start_x + (i * 3), "@@");
        attroff(COLOR_PAIR(i + 1));
    }

    refresh();

    int c;
    while((c = getch()) != 'q') {
        mvprintw(1, 1, "Pressed: %c", c);
        refresh();
    }

    endwin();

    return 0;
}