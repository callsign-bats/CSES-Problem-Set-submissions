#include <stdio.h>

int main()
{
    // how many trailing zeros does n! (= 1*2*3*...*n) end with?
    long long n;
    scanf("%lld", &n);

    // a trailing zero is made by a factor of 10 = 2 * 5. so the count of
    // trailing zeros is the number of times 10 divides n!, which equals
    // min(#twos, #fives) in the prime factorization of n!. multiples of 2
    // are far more common than multiples of 5, so #fives is always the
    // smaller one -- counting fives alone gives the answer.
    //
    // how many fives are in n!? every 5th number contributes one 5
    // (n/5 of them), every 25th contributes an *extra* 5 (n/25), every
    // 125th one more (n/125), and so on. summing n/5 + n/25 + n/125 + ...
    // (integer division) tallies each factor of 5 exactly once.
    long long zeros = 0;
    for (long long p = 5; p <= n; p *= 5)
        zeros += n / p; // integer division floors automatically

    printf("%lld\n", zeros);
}
