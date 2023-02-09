#include "common.h"
#include <stdio.h>

int main(int argv, char* argc[]) {
    if (argv != 3) {
        printf("Pas assez d'arguments\n");
        return 1;
    }
    if (isNumber(argc[1]) == 0) {
        printf("Pas de clef\n");
        return 1;
    }
    int clef = atoi(argc[1]);
    char* message = argc[2];
    int taille = strlen(message);
    char* message_crypte = calloc(taille, sizeof(char));
    for (int i = 0; i < taille; i++) {
        message_crypte[i] = (char)(bon_modulo(message[i] + clef - 'a', 26) + 'a');
    }
    printf("%s\n", message_crypte);
    free(message_crypte);
    return 0;
}