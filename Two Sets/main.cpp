#include <stdio.h>
#include <vector>

int main()
{
    // divide into two sets of equal numers..
    int n;
    scanf("%d", &n);

    // from 1 ------ n
    std::vector<int> set1; // set 1
    long long sum1 = 0;    // set 1 sum
    std::vector<int> set2; // set 2
    long long sum2 = 0;    // set 2 sum..

    // greedy: walk n..1 (largest first), drop each number into whichever
    // set has the smaller sum. big numbers first, small ones fine-tune the
    // balance -- going 1..n instead overshoots and fails (e.g. n=3).
    for (int i = n; i >= 1; i--)
    {
        if (sum1 <= sum2)
        {
            set1.push_back(i);
            sum1 += i;
        }
        else
        {
            set2.push_back(i);
            sum2 += i;
        }
    }

    // if at end its equal print yes with answers else no
    if (sum1 == sum2)
    {
        printf("YES\n");
        printf("%d\n", (int)set1.size());
        for (int x : set1) printf("%d ", x);
        printf("\n");
        printf("%d\n", (int)set2.size());
        for (int x : set2) printf("%d ", x);
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
}
