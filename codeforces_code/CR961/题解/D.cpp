// 位运算 + 动态规划
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;

    // 累计求和数组，统计字符串中字符 c 截止到 j 时出现的次数
    vector<vector<int>> cumsums(c, vector<int>(n + 1));

    for (int i = 0; i < c; ++i)
        for (int j = 0; j < n; ++j)
            cumsums[i][j + 1] = cumsums[i][j] + (s[j] == i + 'A');

    vector<bool> bms(1 << c);

    for (int lo = 0; lo <= n - k; ++lo)
    {
        int ms = 0;
        for (int i = 0; i < c; ++i)
            if (cumsums[i][lo + k] - cumsums[i][lo] != 0)
                ms |= (1 << i);
        bms[ms] = true;
    }
    bms[1 << (s.back() - 'A')] = true;

    vector<bool> bad(1 << c);
    for (int i = 0; i < (1 << c); ++i)
        bad[i] = bms[((1 << c) - 1) ^ i];

    for (int bm = (1 << c) - 1; bm >= 0; --bm)
        for (int b = 0; b < c; ++b)
            bad[bm] = bad[bm | (1 << b)] | bad[bm];

    int res = 1'000'000'000;

    for (int i = 0; i < (1 << c); ++i)
        if (!bad[i])
            res = min(res, __builtin_popcount(i));
    cout << res << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}