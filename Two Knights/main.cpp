#include <stdio.h>

// a stub function that takes in input k and gives out the number of ways to
// place two knights on a k x k board so that neither attacks the other
long long ways(long long k)
{
    // step 1: pick any 2 of the k*k squares.
    //   k*k     = squares free for the 1st knight (board is empty)
    //   k*k - 1 = squares left for the 2nd knight (1 is now taken)
    //   / 2     = knights are identical, so (A,B) == (B,A), counted twice
    long long total = k * k * (k * k - 1) / 2;
    // step 2: two knights attack iff they are the opposite corners of a
    // 2x3 box (that IS the L-move). count those boxes and their pairs:
    //   (k-1)*(k-2) = how many 2x3 boxes fit on the board
    //   x2          = the box can also stand tall as 3x2
    //   x2          = each box holds 2 diagonal attacking pairs
    long long attacking = 4 * (k - 1) * (k - 2);
    // step 3: total counted illegal placements too, so drop them.
    return total - attacking;
}

int main()
{
    // take n input
    int n;
    scanf("%d", &n);

    // for 1 - n compute with that function and print the result
    for (int k = 1; k <= n; k++)
    {
        printf("%lld\n", ways(k));
    }
}
