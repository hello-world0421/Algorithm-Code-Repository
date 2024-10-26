#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums, int limit)
{
    int rank = 0;
    for (int l = 0, r = 0; l < nums.size(); l++)
    {
        while (r + 1 < nums.size() && nums[r + 1] - nums[l] <= limit)
            r++;
        rank += (r - l);
    }
    return rank;
}

int smallestDistancePair(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int l = 0, r = nums.back() - nums.front(), mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check(nums, mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 6, 1};
    cout << smallestDistancePair(nums, 3);

    return 0;
}