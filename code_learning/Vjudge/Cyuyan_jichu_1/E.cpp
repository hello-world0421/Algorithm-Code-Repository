#include <bits/stdc++.h>

using namespace std;
int main(void)
{
    stack<int> nums;
    int temp;
    scanf("%d", &temp);
    while (temp != 0)
    {
        nums.push(temp);
        scanf("%d", &temp);
    }
    while (!nums.empty())
    {
        printf("%d", nums.top());
        nums.pop();
        if (!nums.empty())
            printf(" ");
    }

    return 0;
}