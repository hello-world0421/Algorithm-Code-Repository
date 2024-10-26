// 前缀和 + ? (看不懂)
#include <bits/stdc++.h>
using ll = long long;

void solve()
{
    std::string s;
    std::cin >> s;
    const int n = s.size();
    // 维护前缀和信息
    std::vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);

    // 看不懂
    std::vector<ll> f(2 * n + 1);
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int t = pre[i] + n;
        ans += f[t] * (n - i + 1);
        f[t] += (i + 1);
    }
    std::cout << ans << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}