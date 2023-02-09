#include "Rectangle.h"

int main_rectangle() {
    initscr();
    int mid_x = COLS / 2;
    int mid_y = LINES / 2;

    noecho();
    curs_set(0);

    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);

    attron(COLOR_PAIR(1));
    for (int i = 0; i < 3; i++) {
        move(mid_y + i - 3 / 2, mid_x - 15 / 2);
        for (int i = 0; i < 15; i++) {
            addch(' ');
        }
    }
    attroff(COLOR_PAIR(1));

    getch();
    clear();
    endwin();
    return 0;
}