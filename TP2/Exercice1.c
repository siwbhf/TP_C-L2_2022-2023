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