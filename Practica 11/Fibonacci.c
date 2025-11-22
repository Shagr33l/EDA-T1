#include <stdio.h>
long long fib(long long n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    printf("F(7) = %lld\n", fib(7));
    printf("F(21) = %lld\n", fib(21));
    printf("F(40) = %lld\n", fib(40));
    printf("F(71) = %lld\n", fib(71));
    printf("F(94) = %lld\n", fib(94));
    return 0;
}
