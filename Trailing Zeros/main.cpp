#include <stdio.h>

int main()
{
    // count the trailing zeros of n! (n factorial)
    long long n;
    scanf("%lld", &n);

    // a trailing zero is produced by a factor of 10 = 2 * 5 in the product
    // 1*2*3*...*n. among 1..n the factor 2 is far more common than the factor
    // 5, so the number of trailing zeros is limited by how many 5s appear.
    // so we just count the total power of 5 in n!.
    //
    // how to count 5s: floor(n/5) numbers contribute at least one 5
    // (5,10,15,...), floor(n/25) contribute a *second* 5 (25,50,...),
    // floor(n/125) a third, and so on. summing floor(n/5^i) over all i
    // counts each number once per factor of 5 it holds -> total power of 5.
    long long zeros = 0;
    for (long long p = 5; p <= n; p *= 5) // p = 5, 25, 125, ... while p <= n
    {
        zeros += n / p; // integer division = count of multiples of p up to n
    }

    printf("%lld\n", zeros);
}
