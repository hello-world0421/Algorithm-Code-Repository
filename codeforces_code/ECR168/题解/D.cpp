#include <bits/stdc++.h>
using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // 数组 leaf 表示没有儿子的节点
    std::vector<bool> leaf(n, true);
    // 数组 p 表示 i 号节点的父亲节点
    std::vector<int> p(n);
    p[0] = -1;
    for (int i = 1; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
        leaf[p[i]] = false;
    }
    // 存图，建立有向树的邻接表
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)
        adj[p[i]].push_back(i);
    // 数组 ord 存储除根节点之外的所有节点
    std::vector<int> ord;
    ord.reserve(n - 1);
    // 利用 dfs 求出深度优先搜索序
    auto dfs = [&](auto self, int x) -> void
    {
        if (x != 0)
            ord.push_back(x);
        // 有向树不需要判断是否是父亲节点
        for (auto y : adj[x])
            self(self, y);
    };
    dfs(dfs, 0);

    // 数组 f 表示为了达到目标值还差多少
    std::vector<i64> f(n);
    auto check = [&](i64 x)
    {
        if (a[0] >= x)
            return true;
        f[0] = x - a[0];
        for (auto i : ord)
        {
            if (leaf[i] && f[p[i]] > a[i])
                return false;
            f[i] = f[p[i]] + std::max(0LL, f[p[i]] - a[i]);
            if (f[i] > 1E9)
                return false;
        }
        return true;
    };

    // 二分答案法
    i64 lo = 0, hi = 2E9;
    while (lo < hi)
    {
        i64 x = (lo + hi + 1) / 2;
        if (!check(x))
            hi = x - 1;
        else
            lo = x;
    }
    std::cout << lo << "\n";
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