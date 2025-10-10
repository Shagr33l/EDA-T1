#include <stdio.h>

int main(void) {
    int a[5] = {5, 15, 25, 35, 45}; // nuevos datos
    int *p = a; // p apunta a a[0]

    printf("1) a[1] = %d\n", a[1]); // -> 15

    printf("2) *(a+3) = %d\n", *(a+3)); // -> a[3] = 35

    printf("3) *p++ = %d\n", *p++); // -> 5

    printf("4) *++p = %d\n", *++p); // -> 25

    printf("5) p[1] = %d\n", p[1]); // -> 35

    printf("6) *(p+=2) = %d\n", *(p+=2)); // -> 45

    printf("7) p - a = %d\n", p - a); // -> 4

    return 0;
}
