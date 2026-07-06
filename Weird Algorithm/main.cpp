#include <stdio.h>

int main()
{
    // take in n
    long long n;
    scanf("%lld", &n);

    // if n is even then divide by 2
    // if n is odd multiply by 3 and then plus 1
    // do this till you are 1

    // so 3->(9+1)->5->(15+1)->8->4->2->1

    // while not equal to one process
    while (n != 1)
    {
        // process :
        // print n
        printf("%lld ", n);
        //  if odd treat n*3+1
        if (n % 2 == 1)
            n = n * 3 + 1;
        //  if even treat n/2
        else
            n = n / 2;
        // go back check n
    }

    // print 1
    printf("1\n");

    // return 0
    return 0;
}
