#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

#include <ncurses.h>

int Exercice_1_1_e() {
    initscr();
    move(8, 4);
    for (int i = 0; i < 5; i++) {
        addch("4!+2!"[i]);
    }
    refresh();
    getch();
    endwin();
    return 0;
}

#include <ncurses.h>

int Exercice_1_2_c() {
    initscr();

    attron(A_BOLD);
    attron(A_UNDERLINE);

    printw("Inverse             : ABCabc012\n");

    attroff(A_BOLD);
    attroff(A_UNDERLINE);

    refresh();
    getch();
    endwin();
    return 0;
}

#include <ncurses.h>
int Exercice_1_3_b() {
    initscr();

    start_color();
    init_pair(1, COLOR_RED, COLOR_CYAN);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);

    curs_set(FALSE);

    attron(COLOR_PAIR(1));
    mvprintw(2, 3, "Abc123 **  *");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(2, 16, "2121");
    attroff(COLOR_PAIR(2));

    refresh();
    getch();
    endwin();
    return 0;
}

#include <ncurses.h>
#include <unistd.h>
#define DELAI 20000
int Exercice_2_2_b() {
    int x, y;
    initscr();

    x = 0;
    y = 0;
    while (1) {
        mvaddch(0, 0, '*');
        mvaddch(0, COLS - 1, '*');
        mvaddch(LINES - 1, 0, '*');
        mvaddch(LINES - 1, COLS - 1, '*');

        mvaddch(y, x, 'o');
        refresh();
        mvaddch(y, x, ' ');

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }
    endwin();
    return 0;
}

#include <ncurses.h>
#include <unistd.h>
#define DELAI 20000
int Exercice_2_2_c() {
    int x = 0, y = 0;
    initscr();

    mvaddch(0, 0, '*');
    mvaddch(0, COLS - 1, '*');
    mvaddch(LINES - 1, 0, '*');
    mvaddch(LINES - 1, COLS - 1, '*');
    while (1) {
        mvaddch(y, x, 'o');
        refresh();
        if (x == 0 || x == COLS - 1) {
            if (y == 0 || y == LINES - 1) {
                mvaddch(0, 0, '*');
                mvaddch(0, COLS - 1, '*');
                mvaddch(LINES - 1, 0, '*');
                mvaddch(LINES - 1, COLS - 1, '*');
            }
        } else {
            mvaddch(y, x, ' ');
        }

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }
    endwin();
    return 0;
}

int Exercice_3_1_b() {
    char chaine[80];
    initscr();
    mvgetstr(2, 4, chaine);
    mvprintw(0, 0, "%s", chaine);
    refresh();
    getch();
    endwin();
    return 0;
}

int Exercice_3_1_c() {
    int chaine;
    int x = 0, y = 0;
    initscr();

    do {
        mvscanw(x, y, "%d", &chaine);
        refresh();
        x++;
        y++;
    } while (chaine != 0);

    endwin();
    return 0;
}

#include <ncurses.h>
int Exercice_3_2_b() {
    int touche;
    int x, y;
    int x_prec, y_prec;
    initscr();
    noecho();

    x = COLS / 2;
    y = LINES / 2;
    mvaddch(y, x, 'o');

    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        if (touche == 'q')
            x -= 1;
        if (touche == 'd')
            x += 1;
        if (touche == 'z')
            y -= 1;
        if (touche == 's')
            y += 1;

        if (x < 0)
            x = 0;
        else if (x >= COLS)
            x = COLS - 1;
        if (y < 0)
            y = 0;
        else if (y >= LINES)
            y = LINES - 1;
        mvaddch(y_prec, x_prec, '_');
        mvaddch(y, x, 'o');
        refresh();
    }

    getch();
    endwin();
    return 0;
}

#include <ncurses.h>
int Exercice_3_2_c() {
    int touche;
    int x, y;
    int x_prec, y_prec;
    initscr();
    noecho();

    x = COLS / 2;
    y = LINES / 2;
    mvaddch(y, x, 'o');

    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        if (touche == 'q')
            x -= 1;
        if (touche == 'd')
            x += 1;
        if (touche == 'z')
            y -= 1;
        if (touche == 's')
            y += 1;
        if (touche == 'i') {
            x = COLS / 2;
            y = LINES / 2;
            x_prec = x;
            y_prec = y;
            clear();
        }

        if (x < 0)
            x = 0;
        else if (x >= COLS)
            x = COLS - 1;
        if (y < 0)
            y = 0;
        else if (y >= LINES)
            y = LINES - 1;
        mvaddch(y_prec, x_prec, '_');
        mvaddch(y, x, 'o');
        refresh();
    }

    getch();
    endwin();
    return 0;
}

#include <ncurses.h>
int Exercice_3_2_d() {
    int touche;
    int x, y;
    int x_prec, y_prec;
    int pas = 1;
    initscr();
    noecho();

    x = COLS / 2;
    y = LINES / 2;
    mvaddch(y, x, 'o');
    mvprintw(LINES - 1, 0, "Pas : %d", pas);

    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        switch (touche) {
            case 'p':
                pas++;
                break;
            case 'm':
                if (pas > 1)
                    pas--;
                break;
            case 'q':
                x -= pas;
                break;
            case 'd':
                x += pas;
                break;
            case 'z':
                y -= pas;
                break;
            case 's':
                y += pas;
                break;
            case 'i':
                x = COLS / 2;
                y = LINES / 2;
                x_prec = x;
                y_prec = y;
                clear();
                break;
        }

        if (x < 0)
            x = 0;
        else if (x >= COLS)
            x = COLS - 1;
        if (y < 0)
            y = 0;
        else if (y >= LINES)
            y = LINES - 1;
        mvaddch(y_prec, x_prec, '_');
        mvaddch(y, x, 'o');
        move(LINES - 1, 0);
        for (int i = 0; i < 6 + (int)(pas / 10) + 2; i++) {
            delch();
        }
        mvprintw(LINES - 1, 0, "Pas : %d", pas);
        refresh();
    }

    getch();
    endwin();
    return 0;
}
#include <ncurses.h>
#include <unistd.h>
int Exercice_3_3_b() {
    int touche, val, delai;
    initscr();
    noecho();
    nodelay(stdscr, TRUE);

    val = 0;
    delai = 1000000;
    mvprintw(0, 0, "Valeur : ");
    attron(A_BOLD);
    printw("%3d", val);
    attroff(A_BOLD);
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
                val = 0;
            if (touche == 'b')
                delai /= 2;
            if (touche == 't')
                delai *= 2;
        }
        mvprintw(0, 0, "Valeur : ");
        attron(A_BOLD);
        printw("%3d", val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
    return 0;
}
#include <ncurses.h>
#include <unistd.h>
int Exercice_3_3_c() {
    int touche, val, delai;
    initscr();
    noecho();
    nodelay(stdscr, TRUE);

    val = 0;
    delai = 1000000;
    mvprintw(0, 0, "Valeur : ");
    attron(A_BOLD);
    printw("%3d", val);
    attroff(A_BOLD);
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
                val = 0;
            if (touche == 'b')
                delai /= 2;
            if (touche == 't')
                delai *= 2;
            if (touche == 'q')
                break;
        }
        mvprintw(0, 0, "Valeur : ");
        attron(A_BOLD);
        printw("%3d", val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
    return 0;
}
#include <ncurses.h>
#include <unistd.h>
int Exercice_3_3_d() {
    int touche, val, delai;
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;
    mvprintw(0, 0, "Valeur : ");
    attron(A_BOLD);
    printw("%3d", val);
    attroff(A_BOLD);
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
                val = 0;
            if (touche == KEY_UP)
                delai /= 2;
            if (touche == KEY_DOWN)
                delai *= 2;
            if (touche == 'q')
                break;
        }
        mvprintw(0, 0, "Valeur : ");
        attron(A_BOLD);
        printw("%3d", val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
    return 0;
}

#include <ncurses.h>
#include <unistd.h>
int Exercice_3_3_e() {
    int touche, val, delai;
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;
    mvprintw(0, 0, "Valeur : ");
    attron(A_BOLD);
    printw("%3d", val);
    attroff(A_BOLD);
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
                val = 0;
            if (touche == KEY_UP)
                delai /= 2;
            if (touche == KEY_DOWN)
                delai *= 2;
            if (touche == 'q')
                break;
        }
        mvprintw(0, 0, "Valeur : ");
        attron(A_BOLD);
        printw("%3d", val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
    return 0;
}
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
void dessiner_chat(int y, int x) {
    mvprintw(y, x, "*****");
    mvprintw(y + 1, x, "* * *");
    mvprintw(y + 2, x, "*****");
}

void dessiner_chat_Croix(int y, int x) {
    mvprintw(y, x, "*****");
    mvprintw(y + 1, x, "X * X");
    mvprintw(y + 2, x, "*****");
}

void effacer_chat(int y, int x) {
    mvprintw(y, x, "     ");
    mvprintw(y + 1, x, "     ");
    mvprintw(y + 2, x, "     ");
}

int Exercice_4_2() {
    int touche;
    int chat_x, chat_y;
    int souris_x, souris_y;
    MEVENT ev;

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    chat_x = rand() % (COLS - 4);
    chat_y = rand() % (LINES - 2);
    while (1) {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;
            if ((chat_x <= souris_x) && (souris_x <= chat_x + 4) && (chat_y <= souris_y) && (souris_y <= chat_y + 2)) {
                effacer_chat(chat_y, chat_x);
                chat_x = rand() % (COLS - 4);
                chat_y = rand() % (LINES - 2);
                mvprintw(LINES / 2, COLS / 2 - (int)(strlen("Attrape !") / 2), "Attrape !");
                refresh();
                usleep(500000);
                mvprintw(LINES / 2, COLS / 2 - (int)(strlen("Attrape !") / 2), "         ");
            }
        }
        dessiner_chat(chat_y, chat_x);
        refresh();
    }

    getch();
    endwin();
    return 0;
}

int Exercice_4_3() {
    int touche;
    int chat_x, chat_y;
    int souris_x, souris_y;
    MEVENT ev;

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    chat_x = rand() % (COLS - 4);
    chat_y = rand() % (LINES - 2);
    while (1) {
        FILE *f = fopen("./test.txt", "w");
        fprintf(f, "chat_x = %d, chat_y = %d", chat_x, chat_y);
        fclose(f);
        touche = getch();
        int tmp = getmouse(&ev);
        if (touche == KEY_MOUSE && tmp == OK) {
            souris_x = ev.x;
            souris_y = ev.y;
            if ((chat_x <= souris_x) && (souris_x <= chat_x + 4) && (chat_y <= souris_y) && (souris_y <= chat_y + 2)) {
                effacer_chat(chat_y, chat_x);
                chat_x = rand() % (COLS - 4);
                chat_y = rand() % (LINES - 2);
                mvprintw(LINES / 2, COLS / 2 - (int)(strlen("Attrape !") / 2), "Attrape !");
                refresh();
                usleep(500000);
                mvprintw(LINES / 2, COLS / 2 - (int)(strlen("Attrape !") / 2), "         ");
            }
        } else if ((chat_x == souris_x || souris_x == chat_x + 4) && (chat_y == souris_y + 1)) {
            fprintf(stderr, "test");
            effacer_chat(chat_y, chat_x);
            dessiner_chat_Croix(chat_y, chat_x);
        } else {
            dessiner_chat(chat_y, chat_x);
        }
        refresh();
    }

    getch();
    endwin();
    return 0;
}

int Exercice_5() {
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    curs_set(FALSE);

    for (int i = 0; i < 10; i++) {
        move(LINES - i - 1, 0);
        for (int j = 0; j < 10; j++) {
            int swi = (j + i) % 2 + 1;
            attron(COLOR_PAIR(swi));
            printw(" ");
            attroff(COLOR_PAIR(swi));
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}

int Exercice_6() {
    initscr();
    int n = 0;
    scanw("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        move(i, 0);
        for (int j = 0; j < i; j++) {
            printw("*");
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}

int Exercice_7() {
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int x = COLS / 2, y = LINES / 2;
    int old_x = x, old_y = y;
    int touche;
    int sleep = 100000;
    int loop = 1;

    while (1) {
        touche = getch();
        move(old_y, old_x);
        printw("x");

        old_x = x;
        old_y = y;
        move(y, x);
        printw("o");
        refresh();

        switch (touche) {
            case KEY_UP:
                sleep /= 2;
                break;

            case KEY_DOWN:
                sleep *= 2;
                break;

            case '\n':
                loop = 0;
                break;
        }

        while (loop == 0) {
            touche = getch();
            if (touche == '\n') {
                loop = 1;
            }
        }

        x = x + rand() % 3 - 1;
        y = y + rand() % 3 - 1;
        if (x < 0) {
            x = 0;
        } else if (x > COLS - 1) {
            x = COLS - 1;
        }
        if (y < 0) {
            y = 0;
        } else if (y > LINES - 1) {
            y = LINES - 1;
        }
        usleep(sleep);
    }

    endwin();
    return 0;
}

int Exercice_8() {
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);

    int x = 0, y = 0;
    MEVENT ev;
    int touche;

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < LINES; j++) {
            move(j, i);
            printw("0");
        }
    }

    do {
        touche = getch();
        if (touche == 'p') {
            break;
        }
        int tmp = getmouse(&ev);
        if (touche == KEY_MOUSE && tmp == OK) {
            x = ev.x;
            y = ev.y;
            move(y, x);
            chtype res = winch(stdscr);
            move(y, x);

            if (res == '0') {
                printw("1");
            } else {
                attron(COLOR_PAIR(1));
                printw("2");
                attroff(COLOR_PAIR(1));
            }

            refresh();
        }
    } while (1);

    refresh();
    getch();
    endwin();
    return 0;
}

int main() {
    // Exercice_1_1_e();
    // Exercice_1_2_c();
    // Exercice_1_3_b();

    // Exercice_2_2_b();
    // Exercice_2_2_c();

    // Exercice_3_1_b();
    // Exercice_3_1_c();

    // Exercice_3_2_b();
    // Exercice_3_2_c();
    // Exercice_3_2_d();

    // Exercice_3_3_b();
    // Exercice_3_3_c();
    // Exercice_3_3_d();
    // Exercice_3_3_e();

    // Exercice_4_2();
    // Exercice_4_3();

    // Exercice_5();

    // Exercice_6();

    // Exercice_7();

    Exercice_8();
}