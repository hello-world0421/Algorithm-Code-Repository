#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums, int limit)
{
    int parts = 1;
    long long sum = 0;
    for (int num : nums)
    {
        if (num > limit)
            return 0x7fffffff;
        if (sum + num > limit)
        {
            parts++;
            sum = num;
        }
        else
            sum += num;
    }
    return parts;
}

int splitArray(vector<int> &nums, int k)
{
    int l, r;
    l = 0, r = 0;
    for (int num : nums)
        r += num;
    int mid;
    long long ans;
    while (l <= r)
    {
        mid = l + ((r - l) >> 1);
        if (check(nums, mid) <= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return (int)ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << splitArray(nums, k);

    return 0;
}