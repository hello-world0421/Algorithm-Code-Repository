/*
排序 + 前缀和 + 差分
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    // 0 : 做出该题的时间
    // 1 : 该题的题号
    vector<array<ll, 2>> a(n + 1);
    vector<ll> val(n + 1); // 记录每个题所需时间
    ll ans = 0;

    // 读入做出每题的时间
    for (int i = 1; i <= n; i++)
        cin >> a[i][0], a[i][1] = i;

    // 单独计算罚时
    for (int i = 1, x; i <= n; i++)
        cin >> x, ans += x * 20;

    // 默认按照 0 号位置进行排序
    sort(a.begin() + 1, a.end()); // O(nlogn)
    // 记录每个题所需时间
    for (int i = 1; i <= n; i++)
        val[a[i][1]] = a[i][0] - a[i - 1][0];

    // 利用前缀和求解答案
    ll pre = 0;
    for (int i = 1; i <= n; i++)
        pre += val[i], ans += pre;

    cout << ans;
}

int main()
{
    solve();
    return 0;
}