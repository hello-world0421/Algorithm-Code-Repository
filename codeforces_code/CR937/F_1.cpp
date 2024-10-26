// 贪心算法

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c)
    {
        cout << -1 << '\n';
        return;
    }
    if (a + b + c == 1)
    {
        cout << 0 << '\n';
        return;
    }
    int curr = 1, next = 0, res = 1;
    for (int i = 0; i < a + b; i++)
    {
        if (!curr)
        {
            swap(next, curr);
            res++;
        }
        curr--;
        next++;
        if (i < a)
            next++;
    }
    cout << res << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}
