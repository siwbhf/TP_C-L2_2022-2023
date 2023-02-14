#include "Rectangle.h"

#include <ncurses.h>

#define LARGEUR 15
#define HAUTEUR 3

void rectangle(int y1, int x1, int y2, int x2) {
    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

int main_rectangle() {
    initscr();
    int mid_x = COLS / 2;
    int mid_y = LINES / 2;

    noecho();
    curs_set(0);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    rectangle(mid_y - HAUTEUR / 2, mid_x - LARGEUR / 2, mid_y + HAUTEUR / 2, mid_x + LARGEUR / 2);
    attroff(COLOR_PAIR(1));

    getch();
    clear();
    endwin();
    return 0;
}