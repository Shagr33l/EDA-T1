#include <stdio.h>
long long fib(long long n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    printf("%lld\n", fib(7));
    printf("%lld\n", fib(21));
    printf("%lld\n", fib(40));
    printf("%lld\n", fib(71));
    printf("%lld\n", fib(94));
    return 0;
}
