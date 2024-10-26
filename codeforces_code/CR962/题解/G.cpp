#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<u64> f(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        u64 x = rng();
        f[a] ^= x;
        f[b] ^= x;
    }
    for (int i = 1; i < n; i++)
    {
        f[i] ^= f[i - 1];
    }
    std::map<u64, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(ans, ++cnt[f[i]]);
    }
    std::cout << n - ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
