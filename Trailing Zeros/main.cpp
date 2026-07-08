#include <stdio.h>

int main()
{
    // count the trailing zeros at the end of n! (n factorial).
    long long n;
    scanf("%lld", &n);

    // a trailing zero is made by a factor of 10 = 2 * 5 in the product
    // 1*2*3*...*n. so the number of trailing zeros is how many times 10
    // divides n!, which is min(count of 2s, count of 5s) among the prime
    // factors. 2s are far more common than 5s (every even number gives a 2,
    // only every 5th number gives a 5), so the count of 5s is always the
    // bottleneck -- we just count factors of 5.
    //
    // how many multiples of 5 are in 1..n?  floor(n/5).
    // but 25 = 5*5 contributes TWO 5s, so its extra 5 is counted again by
    // floor(n/25); 125 contributes three, its third 5 caught by floor(n/125);
    // and so on. summing floor(n/5) + floor(n/25) + floor(n/125) + ...
    // therefore counts every factor of 5 exactly once (Legendre's formula).
    long long zeros = 0;
    for (long long p = 5; p <= n; p *= 5)
    {
        zeros += n / p; // integer division floors automatically
    }

    printf("%lld\n", zeros);
}
