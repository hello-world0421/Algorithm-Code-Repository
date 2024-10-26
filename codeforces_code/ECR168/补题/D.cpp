#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    int fa[n], a[n], leaf[n];
    vector<int> adj[n], ord;
    ord.reserve(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fa[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int v;
        cin >> v;
        v--;
        fa[i] = v;
        adj[v].push_back(i);
    }

    // dfs
    auto dfs = [&](auto self, int x) -> void
    {
        if (x != 0)
            ord.push_back(x);
        for (auto s : adj[x])
            self(self, s);
    };
    dfs(dfs, 0);

    vector<ll> f(n);
    auto check = [&](ll x)
    {
        if (a[0] >= x)
            return true;
        f[0] = x - a[0];
        for (auto i : ord)
        {
            if (leaf[i] && f[fa[i]] > a[i])
                return false;
            f[i] = f[fa[i]] + max(0ll, f[fa[i]] - a[i]);
        }
    }

    ll l = 0, r = 2e9;
    while (l < r)
    {

    }
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}