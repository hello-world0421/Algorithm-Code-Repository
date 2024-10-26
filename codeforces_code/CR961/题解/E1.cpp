// 动态规划
#include <bits/stdc++.h>
using namespace std;
constexpr int VB = 2'000'000'001;

void solve()
{
#define M(x) (((x) + 2 * n) % (2 * n))
    int n;
    cin >> n;

    vector<int> v(2 * n);
    for (auto &e : v)
        cin >> e;

    // 考虑 n 为偶数的情况
    // 贪心：通过遍历使得最大值尽可能地小，最小值尽可能地大
    if (n % 2 == 0)
    {
        int ma = 0;
        int mi = VB;
        for (int i = 0; i < n / 2; ++i)
        {
            int s[4]{v[2 * i] + v[2 * i + 1],
                     v[2 * i] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + n + 1],
                     v[2 * i + n] + v[2 * i + 1]};
            sort(s, s + 4);
            ma = max(ma, s[2]);
            mi = min(mi, s[1]);
        }
        cout << ma - mi << '\n';
        return;
    }
    // 特判
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> r;
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        r.push_back(v[cur]);
        r.push_back(v[cur ^= 1]);
        cur = M(cur + n);
    }

    int ans = VB;

    for (int id = 0; id < n; ++id)
        for (int m1 = 0; m1 < 2; ++m1)
            for (int m2 = 0; m2 < 2; ++m2)
            {
                int mi_value = r[M(2 * id - m1)] + r[M(2 * id + 1 + m2)];
                vector<int> dp[2]{
                    vector<int>(n, VB),
                    vector<int>(n, VB)};
                dp[m2][id] = mi_value;
                for (int j = 1; j < n; ++j)
                {
                    int jd = (id + j) % n;
                    int pd = (id + j - 1) % n;
                    for (int pc = 0; pc < 2; ++pc)
                        for (int jc = 0; jc < 2; ++jc)
                            if (dp[pc][pd] != VB && r[M(2 * jd - pc)] + r[M(2 * jd + 1 + jc)] >= mi_value)
                                dp[jc][jd] = min(dp[jc][jd], max(dp[pc][pd], r[M(2 * jd - pc)] + r[M(2 * jd + 1 + jc)]));
                }

                int pd = (id + n - 1) % n;
                if (dp[m1][pd] != VB)
                    ans = min(ans, dp[m1][pd] - mi_value);
            }
    cout << ans << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}