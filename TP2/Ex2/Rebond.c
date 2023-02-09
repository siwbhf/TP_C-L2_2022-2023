#include "Rebond.h"

void draw_rectangle(int x, int y, int col, int largeur, int hauteur) {
    attron(COLOR_PAIR(col));
    move((int)(y - hauteur / 2), (int)(x - largeur / 2));
    for (int j = 0; j < hauteur; j++) {
        for (int i = 0; i < largeur; i++) {
            addch(' ');
        }
        move((int)(y - hauteur / 2) + j, (int)(x - largeur / 2));
    }
    move((int)(y - hauteur / 2), (int)(x - largeur / 2));
    // refresh();
    attroff(COLOR_PAIR(col));
}

void draw_carre(int x, int y, int col, int cote) {
    attron(COLOR_PAIR(col));
    move((int)(y - cote / 2), (int)(x - cote / 2));
    for (int j = 0; j < cote; j++) {
        for (int i = 0; i < cote; i++) {
            addch(' ');
        }
        move((int)(y - cote / 2) + j, (int)(x - cote / 2));
    }
    move((int)(y - cote / 2), (int)(x - cote / 2));
    // refresh();
    attroff(COLOR_PAIR(col));
}

int main_loop(int speed) {
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    int col = 1;
    attron(COLOR_PAIR(col));

    int touche;

    nodelay(stdscr, TRUE);

    int midx = getmaxx(stdscr) / 2 - 1;
    int midy = getmaxy(stdscr) / 2 - 1;

    int carrX = midx;
    int carrY = midy;
    int Rectx = midx;
    int Recty = midy;
    int direction = 0;
    int colCarre = 1;
    draw_rectangle(Rectx, Recty, 3, 6, 6);
    draw_carre(carrX, carrY, colCarre, COT);

    int moving = 0;
    while (1) {
        touche = getch();

        if (moving) {
            usleep(1000000 / speed);
            draw_rectangle(Rectx, Recty, 3, 6, 6);
            if ((carrX + COT / 2 >= Rectx + 3 && carrY - COT / 2 <= Recty - 3) || (carrX - COT / 2 <= Rectx - 3 && carrY + COT / 2 >= Recty + 3)) {
                direction = direction == 0 ? 1 : 0;
                colCarre = colCarre == 1 ? 2 : 1;
            }
            if (direction == 0) {
                carrX++;
                carrY--;
            }
            if (direction == 1) {
                carrX--;
                carrY++;
            }
            draw_carre(carrX, carrY, colCarre, COT);
        }
        if (touche == 'q' || touche == 'Q') {
            break;
        }
        if (touche == KEY_ENTER || touche == 10) {
            moving = moving == 0 ? 1 : 0;
            if (moving == 0) {
                break;
            }
        }
        refresh();
    }
    return 0;
}

int main_rebond() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    main_loop(2);
    clear();
    endwin();
    return 0;
}
