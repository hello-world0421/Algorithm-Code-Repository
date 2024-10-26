#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 4e5 + 7;
const int MOD = 998244353;

ll func(ll x, ll k)
{
    ll T = 1ll << (k + 1);
    ll val = T / 2;
    x++;
    ll res = x / T * val;
    ll r = x % T;
    r -= val;
    if (r > 0)
        res += r;
    return res;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    const int LOG = ceil(log2(r));
    for (int i = LOG; i >= 0; i--)
    {
        ll p = (func(r, i) % MOD - func(l - 1, i) % MOD + MOD) % MOD;
        ans = (ans + p) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}