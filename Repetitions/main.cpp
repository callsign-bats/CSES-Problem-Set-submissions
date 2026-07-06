#include <stdio.h>
#include <string.h>

int main()
{
    // given A C G T
    // a seq eg -> AGGGGGGCTTTT so ans is 6
    // returned is the longest substring with same characters..

    static char str[1000006];
    scanf("%s", str);

    // go over one by one
    // before create a variable current max = 0
    int current_max = 0;
    // another current_len = 0
    int current_len = 0;
    // another current char =>''
    char current_char = '\0';
    // another previouds char => ''
    char previous_char = '\0';

    // loop from 0 top strlen-1
    for (int index = 0; index <= (int)strlen(str) - 1; index++)
    {
        // curr char is str[index]
        current_char = str[index];
        // previous = str[index-1]
        previous_char = str[index - 1];
        // if curr == prevoious then currenlen++
        if (current_char == previous_char)
            current_len++;
        // if not then current_len = 1;
        else
            current_len = 1;
        // then always current max = max of (current , current_max)
        if (current_len > current_max)
            current_max = current_len;
    }

    // print current max
    printf("%d\n", current_max);
    return 0;
}
