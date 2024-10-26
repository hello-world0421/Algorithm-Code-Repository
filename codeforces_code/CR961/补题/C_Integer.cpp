#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> a;

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1] && a[i] == 1)
        {
            cout << "-1\n";
            return;
        }

    vector<ll> rem(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        ll last = a[i - 1];
        ll cur = a[i];
        ll extra = 0;
        while (last != 1 && last * last <= cur)
            extra--, last *= last;
        while (cur < last)
            extra++, cur *= cur;
        rem[i] = max(0ll, rem[i - 1] + extra);
    }
    ll ans = accumulate(rem.begin() + 1, rem.end(), 0ll);
    cout << ans << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}