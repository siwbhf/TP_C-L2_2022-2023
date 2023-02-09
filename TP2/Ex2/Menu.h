#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

void draw_main(int choix, int color_pair);
void draw_options(int speed);
void draw_credits();
int main_menu();

#endif