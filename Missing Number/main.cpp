#include <stdio.h>

int main()
{
    // take in n
    long long n;
    scanf("%lld", &n);

    // read the n-1 numbers and figure out which one from 1..n is missing

    // loop from 0 to n-1
    // scan inputs..
    // store in a sum
    long long sum = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        long long x;
        scanf("%lld", &x);
        sum = sum + x;
    }

    // calcualte n*n+1/2 basically sum of all numbers.. and subtract previus sum from it and reutrn that value..
    long long total = n * (n + 1) / 2;
    printf("%lld\n", total - sum);

    // return 0
    return 0;
}
