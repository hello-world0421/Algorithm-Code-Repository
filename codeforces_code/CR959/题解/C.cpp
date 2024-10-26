// 动态规划
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        // 学习 ！！
        // 求解一维的前缀和很方便
        partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
        vector<int> dp(n + 2);
        for (int i = n - 1; i >= 0; --i)
        {
            // 返回给定的有序序列中的第一个大于给定值的索引
            int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            dp[i] = dp[q] + q - i - 1;
        }
        // C++ 中常用的求和函数
        cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
    }
}