#ifndef REBOND_H
#define REBOND_H

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#define COT 2

void draw_rectangle(int x, int y, int col, int largeur, int hauteur);
void draw_carre(int x, int y, int col, int cote);
int main_loop(int speed);
int main_rebond();

#endif