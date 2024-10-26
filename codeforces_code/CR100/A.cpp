#include <bits/stdc++.h>
using namespace std;
int a, b, c;

bool check(int round)
{
    return (a + b + c - round * 9) <= 0;
}

void solve()
{
    cin >> a >> b >> c;
    int ans = -1;
    for (int l = 1, r = a + b + c, mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check(mid))
        {
            if (a + b + c - mid * 9 == 0 && min({a, b, c}) >= mid)
                ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << (ans == -1 ? "NO" : "YES") << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}