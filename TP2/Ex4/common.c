#include "common.h"

int isNumber(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int bon_modulo(int a, int b) {
    return a % b < 0 ? a % b + b : a % b;
}