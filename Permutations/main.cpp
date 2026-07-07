#include <stdio.h>

int main()
{
    // print a beautiful permutatoin
    // it is said to be beautiful if... no adjecent has a diff of 1 eg 4 2 5 3 1
    // you are given n

    int n;
    scanf("%d", &n);

    // if n = 0, 1, 2 , 3 print nohting..
    if (n == 0 || n == 2 || n == 3)
    {
        // print "NO SOLUTION"
        printf("NO SOLUTION\n");
        return 0;
    }

    // var module_1 => 1 & not module_2 !=0
    // var modulo_2 => 2

    // var current_num = 1
    int current_num = n;

    // while currnt_num < n
    while (current_num > 0)
    {
        // if(n%2!=0)
        if (current_num % 2 != 0)
            // print n
            printf("%d ", current_num);
        // n++
        current_num--;
    }

    // current_num = 1;
    current_num = n;
    // while currnt_num< n
    while (current_num > 0)
    {
        // if(n%2==0)
        if (current_num % 2 == 0)
            // print n
            printf("%d ", current_num);
        // n++
        current_num--;
    }

    // done
    printf("\n");
}