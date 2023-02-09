#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int isNumber(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main(int argv, char *argc[]) {
    if (argv != 3) {
        printf("Usage: <number> <character>");
        return 1;
    }
    if (!isNumber(argc[1])) {
        printf("Usage: <number> <character>");
        return 1;
    }
    int nb = atoi(argc[1]);
    char c = argc[2][0];

    initscr();
    noecho();
    int midx = getmaxx(stdscr) / 2 - 1;
    int midy = getmaxy(stdscr) / 2 - 1;

    for (int i = 1; i < nb * 2 + 3; i += 2) {
        int ind_inv = nb * 2 + 2 - i;

        for (int j = 0; j < ind_inv; j++) {
            mvaddch(midy + i / 2 - nb / 2, midx - ind_inv / 2 + j, c);
            refresh();
        }
    }

    getch();
    endwin();
    return 0;
}