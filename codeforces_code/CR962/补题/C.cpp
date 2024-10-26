// 维护前缀和，时间复杂度为 O(n + q)
// 根据题目给出的数据量，时间大概不超过 2e8，完美！
#include <bits/stdc++.h>

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::string a, b;
    std::cin >> a >> b;

    std::vector<std::array<int, 26>> pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i];
        pre[i + 1][a[i] - 'a']++;
        pre[i + 1][b[i] - 'a']--;
    }
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--;
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += std::max(0, pre[r][i] - pre[l][i]);
        std::cout << ans << '\n';
    }
}

int main()
{
    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}