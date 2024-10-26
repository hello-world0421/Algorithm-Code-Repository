// 递归，时间复杂度为：O(logn)
#include <bits/stdc++.h>
using ll = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    // 数组 v 存储每个阶段的总长度
    std::vector<int> v;
    while (n)
    {
        v.push_back((n + 1) / 2);
        n /= 2;
    }
    // tot 表示之前阶段积累的长度，pow2 表示递归的子问题结果回溯的系数
    int tot = 0, pow2 = 1;
    for (int x : v)
    {
        if (tot < k && k <= tot + x)
        {
            std::cout << pow2 * (2 * (k - tot) - 1) << '\n';
            return;
        }
        tot += x;
        pow2 *= 2;
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