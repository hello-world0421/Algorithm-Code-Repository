// 动态规划

#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, sum, n) for (int i = sum; i < n; i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n), g(n);
    vector<string> aa(n), bb(n);
    vector<string> vals;
    rep(i, 0, n)
    {
        string a, b;
        cin >> a >> b;
        vals.push_back(a);
        vals.push_back(b);
        aa[i] = a, bb[i] = b;
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    rep(i, 0, n)
    {
        s[i] = lower_bound(all(vals), aa[i]) - vals.begin();
        g[i] = lower_bound(all(vals), bb[i]) - vals.begin();
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    rep(i, 0, n)
        dp[1 << i][i] = 1;
    rep(mask, 0, (1 << n))
        rep(lst, 0, n)
        {
            if (!dp[mask][lst])
                continue;
            rep(i, 0, n)
            {
                if (mask >> i & 1)
                    continue;
                if (s[lst] == s[i] || g[lst] == g[i])
                    dp[mask | (1 << i)][i] |= dp[mask][lst];
            }
        }
    int ans = 0;
    rep(mask, 0, (1 << n))
        rep(i, 0, n)
            if (dp[mask][i])
                ans = max(ans, __builtin_popcount(mask));
    cout << n - ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}
