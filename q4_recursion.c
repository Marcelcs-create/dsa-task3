/* Q4: Recursive programs (a) sum of first N naturals (b) factorial
 *     (c) Nth Fibonacci term (d) first N Fibonacci terms. */
#include <stdio.h>

long long sumN(int n)       { return n <= 0 ? 0 : n + sumN(n - 1); }          /* (a) */
long long factorial(int n)  { return n <= 1 ? 1 : n * factorial(n - 1); }     /* (b) */
long long fib(int n)        { return n <= 1 ? n : fib(n - 1) + fib(n - 2); }  /* (c) F0=0,F1=1 */

void printFib(int n, int i) {                                                 /* (d) */
    if (i >= n) return;
    printf("%lld ", fib(i));
    printFib(n, i + 1);
}

int main(void) {
    int n;
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 0) { printf("Invalid input\n"); return 1; }
    printf("(a) Sum of first %d natural numbers = %lld\n", n, sumN(n));
    if (n <= 20) printf("(b) %d! = %lld\n", n, factorial(n));
    else         printf("(b) %d! overflows long long (max N is 20)\n", n);
    printf("(c) Fibonacci term %d = %lld\n", n, fib(n));
    printf("(d) First %d Fibonacci terms: ", n);
    printFib(n, 0);
    printf("\n");
    return 0;
}
