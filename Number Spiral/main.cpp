#include <stdint.h>
#include <stdio.h>

// a function that returns.. teh value and takes in coordinates...
// x , y
long long value(long long x, long long y);

// funciton for manhattan disatnce ( x1, x2 , y1 , y2 )
long long manhattan(long long x1, long long x2, long long y1, long long y2);

int main()
{
    // a grid with start siwth 1 on top left
    // 1 2
    // 4 3

    //  >   v   >   v
    //  v   <   A   v
    //  >   >   A

    // input n and pairs
    // n is numbner of test
    // pairs is cords to return..
    // example 3 , 1 will be => 5 3 is row number and 1 is column number 1 , 1 is one..

    // input n and pairs
    // n is numbner of test
    int n;
    scanf("%d", &n);

    // create soltuions array of lenth n
    long long solutions[100000];

    // loop number of times..
    for (int i = 0; i < n; i++)
    {
        // take in both input and compute the function..
        long long x, y;
        scanf("%lld %lld", &x, &y);
        // store value in soltuions array
        solutions[i] = value(x, y);
    }

    // iterate over the solution array and print one by one..
    for (int i = 0; i < n; i++)
        printf("%lld\n", solutions[i]);

    // return
    return 0;
}

// a function that returns.. teh value and takes in coordinates...
// x , y
long long value(long long x, long long y)
{
    // HINT: think in "rings/layers". Each ring is decided by m = max(row, col).
    //       ring 1 is just {1}, ring 2 wraps around it, ring 3 wraps that, etc.

    // HINT: the biggest number on ring m is exactly m*m, and it sits on a corner.
    //       ring 1 -> 1, ring 2 -> 4, ring 3 -> 9, ring 4 -> 16 ...
    //       so everything on ring m lives in the range (m-1)*(m-1)+1 .. m*m

    // HINT: which corner holds m*m flips with the parity of m.
    //       even m -> the corner m*m is at the bottom-left  (row = m, col = 1)
    //       odd  m -> the corner m*m is at the top-right     (row = 1, col = m)

    // HINT: figure out if your cell is on the vertical arm or the horizontal arm.
    //       if col >= row  -> you are on the right column (col is the max = m)
    //       if row >  col  -> you are on the bottom row   (row is the max = m)

    // HINT: once you know m and which arm, just count steps away from a known
    //       corner. one arm counts up from (m-1)*(m-1), the other counts down
    //       from m*m. use row (or col) as the offset. mind the parity flip.

    // STORE A BOOL  is bottom row else it will be right column.. = if( x > y)
    bool is_bottom_row = (x > y);

    // store ring number if bottom row => x else its y
    long long ring = is_bottom_row ? x : y;

    // known value (max) is ring number * ring number min is (ring number -1 )* (ring number - 1 )+1
    long long max = ring * ring;
    long long min = (ring - 1) * (ring - 1) + 1;

    // if ring number is even max is on bottom left ( ring number , 1)
    long long max_x, max_y;
    if (ring % 2 == 0)
    {
        max_x = ring;
        max_y = 1;
    }
    // else its on 1 , ring number
    else
    {
        max_x = 1;
        max_y = ring;
    }

    // man hattaon distance from max
    long long dist = manhattan(max_x, x, max_y, y);

    // ans is max - manhattan distance
    return max - dist;
}

// funciton for manhattan disatnce ( x1, x2 , y1 , y2 )
long long manhattan(long long x1, long long x2, long long y1, long long y2)
{
    // its y2 - y1 + x2 - x1
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    return dx + dy;
}