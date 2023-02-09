#include "Menu.h"
#include "Rebond.h"

void draw_main(int choix, int color_pair) {
    char *textes[] = {"1 - Demarrer", "2 - Options", "3 - Credits", "4 - Quitter"};

    for (int i = 0; i < 4; i++) {
        move(LINES / 2 + i - 2, COLS / 2 - 10);
        if (i == choix) {
            attron(COLOR_PAIR(color_pair));
            addstr(textes[i]);
            attroff(COLOR_PAIR(color_pair));
        } else {
            addstr(textes[i]);
        }
    }
}

void draw_options(int speed) {
    mvprintw(LINES / 2 - 2, COLS / 2 - 10, "Appuyez sur + ou - pour changer la vitesse");
    mvprintw(LINES / 2 - 3, COLS / 2 - 10, "Appuyez sur n'importe quelle autre touche pour revenir au menu");
    mvprintw(LINES / 2 - 1, COLS / 2 - 10, "Vitesse actuelle : ");
    attron(COLOR_PAIR(1));
    printw("%d", speed);
    attroff(COLOR_PAIR(1));
}

void draw_credits() {
    mvprintw(LINES / 2 - 2, COLS / 2 - strlen("Ce jeu a ete realise par :") / 2, "Ce jeu a ete realise par :");
    mvprintw(LINES / 2 - 1, COLS / 2 - strlen("BAILLARGEAU Axel, Etudient de 2eme annee a l'UPEM") / 2, "BAILLARGEAU Axel, Etudient de 2eme annee a l'UPEM");
    mvprintw(LINES / 2, COLS / 2 - strlen("BOUHAFA Siwar, Etudient de 2eme annee a l'UPEM") / 2, "BOUAFA Siwar, Etudient de 2eme annee a l'UPEM");
    mvprintw(LINES / 2 + 1, COLS / 2 - strlen("Appuyez sur n'importe quelle touche pour revenir au menu") / 2, "Appuyez sur n'importe quelle touche pour revenir au menu");
}

int main_menu() {
    initscr();
    int choix = 0;
    int touche = -1;
    int entrer = 0;
    int speed = 2;

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    draw_main(choix, 1);
    refresh();

    while (1) {
        touche = getch();
        switch (touche) {
            case KEY_UP:
                choix = choix == 0 ? 3 : choix - 1;
                break;

            case KEY_DOWN:
                choix = choix == 3 ? 0 : choix + 1;
                break;

            case 'q':
                break;

            case 10:
                entrer = 1;
                break;

            case '1':
                choix = 0;
                entrer = 1;
                break;

            case '2':
                choix = 1;
                entrer = 1;
                break;

            case '3':
                choix = 2;
                entrer = 1;
                break;

            case '4':
                choix = 3;
                entrer = 1;
                break;

            default:
                break;
        }

        if (entrer) {
            int refr = 1;
            switch (choix) {
                case 0:
                    // Demarrer
                    clear();
                    main_loop(speed);
                    endwin();
                    return 0;

                case 1:
                    // Options
                    clear();
                    draw_options(speed);
                    while (1) {
                        touche = getch();
                        if (touche == '+') {
                            speed = speed == 10 ? 10 : speed + 1;
                            refr = 1;
                        } else if (touche == '-') {
                            speed = speed == 1 ? 1 : speed - 1;
                            refr = 1;
                        } else {
                            break;
                        }
                        if (refr) {
                            draw_options(speed);
                            refresh();
                            refr = 0;
                        }
                    }
                    entrer = 0;
                    refr = 1;
                    clear();
                    break;

                case 2:
                    // Credits
                    entrer = 0;
                    clear();
                    draw_credits();
                    refresh();
                    getch();
                    clear();
                    break;

                case 3:
                    // Quitter
                    return 0;
                    break;

                default:
                    break;
            }
        }
        draw_main(choix, 1);
        refresh();
    }
    return 0;
}
