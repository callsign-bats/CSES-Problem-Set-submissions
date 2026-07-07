#include <stdio.h>

int main()
{
    // array of n integers.. is given..arr
    // modify such that next element is equal or more than previous..
    // count number of moves such that..
    // you can increase the value of any element by one counts as one move..

    // 5
    // 3 2 5 1 7

    // if arr is of one elemnt or less return 0
    // start from second element in arr and loop
    // store move = 0
    // store current_number = arr[0]
    // for i = 1 to i = n-1
    // previous = arr[i-1]
    // current = arr[i];
    // if (current < current_number)
    //  move +=current_number - current
    // else current_number = current

    // out of loop print.. moves

    int n;
    scanf("%d", &n);

    int arr[200000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // if arr is of one elemnt or less return 0
    if (n <= 1)
    {
        printf("0\n");
        return 0;
    }

    // store move = 0
    long long move = 0;
    // store current_number = arr[0]
    long long current_number = arr[0];

    // for i = 1 to i = n-1
    for (int i = 1; i < n; i++)
    {
        // previous = arr[i-1]
        int previous = arr[i - 1];
        // current = arr[i];
        int current = arr[i];
        // if (current < current_number)
        if (current < current_number)
            //  move +=current_number - current
            move += current_number - current;
        // else current_number = current
        else
            current_number = current;
    }

    printf("%lld\n", move);
}