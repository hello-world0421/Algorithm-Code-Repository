// 一道数学题，时间复杂度为 O(n * logn) (调和级数)
#include <bits/stdc++.h>

void solve()
{
    int n, x;
    std::cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= x && a <= n / 2; a++)
        for (int b = 1; a * b <= n && a + b <= x; b++)
            ans += std::min((n - a * b) / (a + b), x - a - b);
    std::cout << ans << '\n';
}

int main()
{
    int tt;
    std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}