#include <stdio.h>
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
    if (argv != 4) {
        printf("Usage: <number> <operator> <number>");
        return 1;
    }
    if (!isNumber(argc[1]) || !isNumber(argc[3])) {
        printf("Usage: <number> <operator> <number>");
        return 1;
    }
    int op1 = atoi(argc[1]);
    int op2 = atoi(argc[3]);
    char op = argc[2][0];
    if (op == '+') {
        printf("%d + %d = %d", op1, op2, op1 + op2);
    } else if (op == '-') {
        printf("%d - %d = %d", op1, op2, op1 - op2);
    } else if (op == 'x') {
        printf("%d * %d = %d", op1, op2, op1 * op2);
    } else if (op == '/') {
        printf("%d / %d = %d", op1, op2, op1 / op2);
    } else {
        printf("Usage: <number> <operator> <number>");
        return 1;
    }
    return 0;
}