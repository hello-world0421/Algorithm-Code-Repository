#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &piles, int speed)
{
    int times = 0;
    for (int pile : piles)
        times += (pile + speed - 1) / speed;
    return times;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int l, r;
    l = 1;
    r = 0;
    for (int pile : piles)
        r = max(r, pile);
    int ans = 0;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(piles, mid) <= h)
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
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 6;
    cout << minEatingSpeed(piles, h);

    return 0;
}