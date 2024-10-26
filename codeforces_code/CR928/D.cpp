#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int ans = 0;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (!mp[x])
            ans++, mp[((1 << 31) - 1) ^ x]++;
        else
            mp[x]--;
    }
    std::cout << ans << '\n';
}

int main()
{
    int tt;
    std::cin >> tt;
    while(tt--)
        solve();

    return 0;
}