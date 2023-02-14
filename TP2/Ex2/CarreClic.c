#include "CarreClic.h"

void draw_carre_1(int x, int y, int width, int color_pair) {
    attron(COLOR_PAIR(color_pair));
    mvhline(y - width / 2, x - width / 2, 0, width);
    mvhline(y + width / 2, x - width / 2, 0, width);
    mvvline(y - width / 2, x - width / 2, 0, width);
    mvvline(y - width / 2, x + width / 2, 0, width);
    mvaddch(y - width / 2, x - width / 2, ACS_ULCORNER);
    mvaddch(y + width / 2, x - width / 2, ACS_LLCORNER);
    mvaddch(y - width / 2, x + width / 2, ACS_URCORNER);
    mvaddch(y + width / 2, x + width / 2, ACS_LRCORNER);
    // for (int i = 0; i < width; i++) {
    //     move(y + i - width / 2, x - width / 2);
    //     for (int i = 0; i < width; i++) {
    //         addch(' ');
    //     }
    // }
    attroff(COLOR_PAIR(color_pair));
}

int main_carre_clic() {
    initscr();
    int mid_x = COLS / 2;
    int mid_y = LINES / 2;

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    mousemask(ALL_MOUSE_EVENTS, NULL);
    MEVENT ev;

    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int touche = -1;

    int refr = 0;
    int col = 1;
    draw_carre_1(mid_x, mid_y, 15, col);
    refresh();

    while (1) {
        if (refr) {
            col = col % 2 + 1;
            draw_carre_1(mid_x, mid_y, 15, col);
            refresh();
            refr = 0;
        }
        touche = getch();
        int tmp = getmouse(&ev);
        if (touche == KEY_MOUSE && tmp == OK) {
            if (ev.bstate & BUTTON1_CLICKED) {
                int x = ev.x;
                int y = ev.y;
                if (x >= mid_x - 15 / 2 && x <= mid_x + 15 / 2 && y >= mid_y - 15 / 2 && y <= mid_y + 15 / 2) {
                    refr = 1;
                }
            }
        } else if (touche == 'q') {
            break;
        }
    }

    getch();
    clear();
    endwin();
    return 0;
}
