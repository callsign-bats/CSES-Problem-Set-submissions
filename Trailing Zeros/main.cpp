#include <stdio.h>

// how many trailing zeros does n! (= 1*2*3*...*n) end with?
//
// a trailing zero is produced by a factor of 10, and 10 = 2 * 5.
// so the number of trailing zeros = how many times 10 divides n!,
// which = min(count of 2s, count of 5s) in the prime factorization of n!.
//
// key observation: 2s are FAR more common than 5s (every 2nd number is
// even, but only every 5th is a multiple of 5). so 5s are always the
// bottleneck -> the answer is simply "how many factors of 5 are in n!".
//
// counting factors of 5 in n! (Legendre's formula):
//   floor(n/5)   numbers in [1..n] contribute at least one 5   (5,10,15,...)
// + floor(n/25)  contribute a SECOND 5                          (25,50,75,...)
// + floor(n/125) contribute a THIRD 5                           (125,250,...)
// + ...          until the divisor exceeds n.
// each multiple of 25 was only counted once by floor(n/5), so floor(n/25)
// adds the extra 5 it also carries; same reasoning for 125, 625, and so on.
// summing these floors gives the exact total count of 5s (hence of 10s).

int main()
{
    long long n;
    scanf("%lld", &n);

    // accumulate n/5 + n/25 + n/125 + ...
    // we grow the divisor by *5 each step. it's a long long because for
    // n up to 1e9 the divisor climbs past 1e9 (into the billions) before
    // the loop stops, which would overflow a 32-bit int.
    long long zeros = 0;
    for (long long div = 5; div <= n; div *= 5)
        zeros += n / div; // integer division = how many multiples of 'div' are <= n

    printf("%lld\n", zeros);
}
