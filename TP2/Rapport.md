# TP2

Baillargeau Axel
BOUHAFA Siwar

## Introduction

Le but de ce TP est de mettre en pratique les notions vues en cours sur les chaînes de caractères et les fonctions de la bibliothèque standard ainsi que la bibliothèque Ncurses.

## 1. Documentation man

### 1.1

La fonction strcmp compare deux chaînes de caractères et renvoie 0 si elles sont identiques, un nombre positif si la première est supérieure à la seconde et un nombre négatif si la première est inférieure à la seconde. La comparaison se fait en fonction de la valeur ASCII des caractères.

### 1.2

```c
#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strcmp("H", "H"));                // 0
    printf("%d\n", strcmp("H", "h"));                // -1
    printf("%d\n", strcmp("a", "b"));                // -1
    printf("%d\n", strcmp("Hello", "Hello"));        // 0
    printf("%d\n", strcmp("Hello", "Hello World"));  // -1
    printf("%d\n", strcmp("Hello World", "Hello"));  // 1
    printf("%d\n", strcmp("H", "Hello"));            // -1
    printf("%d\n", strcmp("Hello", "H"));            // 1
}
```

### 1.3

strchr renvoie un pointeur sur la première occurrence du caractère c dans la chaîne s. Si le caractère n'est pas trouvé, la fonction renvoie NULL.

strrchr renvoie un pointeur sur la dernière occurrence du caractère c dans la chaîne s. Si le caractère n'est pas trouvé, la fonction renvoie NULL.

### 1.4

```c
#include <stdio.h>
#include <string.h>

int main() {
    printf("%s\n", strchr("Hello World", 'H'));  // Hello World
    printf("%s\n", strrchr("Hello World", 'e'));  // ello World
    printf("%s\n", strchr("Hello World", ' '));  //  World
    printf("%s\n", strchr("Hello World", 'o'));  // o World
    printf("%s\n", strrchr("Hello World", 'o'));  // orld
    printf("%s\n", strrchr("Hello World", 'x'));  // (null)
    printf("%s\n", strchr("Hello World", 'h'));  // (null)
}
```

### 1.5

La fonction atoi convertit la chaîne de caractères s en un entier. Si la chaîne ne représente pas un entier, la fonction renvoie 0.

### 1.6

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", atoi("123"));  // 123
    printf("%d\n", atoi("123.4"));  // 123
    printf("%d\n", atoi("123.4.5"));  // 123
    printf("%d\n", atoi("abc"));  // 0
    printf("%d\n", atoi("123abc"));  // 123
    printf("%d\n", atoi("abc123"));  // 0
}
```

## 2. Complements sur Ncurses

## 3. Cryptage de César

### 3.5
