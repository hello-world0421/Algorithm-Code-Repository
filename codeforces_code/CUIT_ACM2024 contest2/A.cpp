#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    if (n > 12)
    {
        std::cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = i; j <= 6; j++)
            if (i + j == n)
                cnt++;
    std::cout << cnt << '\n';
}

int main()
{
    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}