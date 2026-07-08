#include <stdio.h>

// MOD = 10^9 + 7. why this exact number?
//   - 2^n for n up to 1e6 has ~300000 digits, too big to store/print,
//     so the problem asks for the answer mod this fixed number instead.
//   - it is prime: every nonzero value has a modular inverse (handy for
//     division/nCr problems; the community default for that reason).
//   - it fits in 32 bits, and MOD*MOD ~ 1e18 fits in a 64-bit long long,
//     so result*base below never overflows before the % is applied.
//   - the "+7" is just the smallest offset that makes 1e9+7 prime.
const long long MOD = 1000000007;

long long power(long long base, long long exp); // custom pow, declared

int main()
{
    // bit strings possible for n
    long long n;
    scanf("%lld", &n);

    // print 2 to the power n
    printf("%lld\n", power(2, n));
}

// custom pow implemetation..
// idea: instead of multiplying base exp times (O(exp), too slow for 1e6),
// use the binary form of exp. why this works:
//   any exp is a sum of powers of 2, e.g. 13 = 1101b = 8 + 4 + 1, so
//   base^13 = base^8 * base^4 * base^1. we walk exp bit by bit: each step
//   'base' holds base^(1,2,4,8,...) by repeated squaring, and we fold it
//   into result only when that bit of exp is set. that is O(log exp).
// the % MOD after every multiply keeps numbers under 1e9+7 so a product
// stays under 1e18 and never overflows the 64-bit long long.
long long power(long long base, long long exp)
{
    long long result = 1;
    // reduce base once up front: if the caller passes a base >= MOD, this
    // guarantees base < MOD before the loop, so the very first
    // base*base stays under 1e18 and can't overflow. (for us base=2 so
    // it's a no-op, but it makes power() safe for any base.)
    base %= MOD;
    while (exp > 0)
    {
        if (exp & 1) result = result * base % MOD; // this bit set -> fold base^(2^i) in
        base = base * base % MOD;                  // square: base^(2^i) -> base^(2^(i+1))
        exp >>= 1;                                 // drop that bit, move to next
    }
    return result;
}
