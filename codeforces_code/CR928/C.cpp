#include <bits/stdc++.h>
constexpr int MAXN = 2e5 + 1;
std::array<int, MAXN> ans = {0};

int bitSum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += (x % 10);
        x /= 10;
    }
    return res;
}

void solve()
{
    int n;
    std::cin >> n;
    std::cout << ans[n] << '\n';
}

int main()
{
    for (int i = 1; i < MAXN; i++)
        ans[i] = ans[i - 1] + bitSum(i);
    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}