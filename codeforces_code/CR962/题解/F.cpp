#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto get = [&](int v)
    {
        i64 sum = 0;
        i64 cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] >= v)
            {
                i64 t = (a[i] - v) / b[i] + 1;
                cnt += t;
                sum += a[i] * t - t * (t - 1) / 2 * b[i];
            }
        return std::pair{cnt, sum};
    };

    // 二分
    int lo = 0, hi = 1E9 + 1;
    while (lo < hi)
    {
        int x = (lo + hi) / 2;
        if (get(x).first <= k)
            hi = x;
        else
            lo = x + 1;
    }
    auto [cnt, sum] = get(lo);
    if (lo > 0)
        sum += (k - cnt) * (lo - 1);
    std::cout << sum << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
