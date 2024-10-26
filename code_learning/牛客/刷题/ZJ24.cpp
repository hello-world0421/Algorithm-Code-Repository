#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int h[MAXN], n;

bool check(int mid, int max)
{
    int ans = mid;
    for (int i = 1; i <= n; i++)
    {
        if (ans <= h[i])
            ans -= (h[i] - ans);
        else
            ans += (ans - h[i]);
        if (ans >= max)
            return true;
        if (ans < 0)
            return false;
    }
    return true;
}

int compute(int l, int r, int max)
{
    int ans = -1;
    int mid = 0;
    while (l <= r)
    {
        mid = l + ((r - l) >> 1);
        if (check(mid, max))
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
    cin >> n;
    int l, r;
    l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        r = max(r, h[i]);
    }
    cout << compute(l, r, r);
}