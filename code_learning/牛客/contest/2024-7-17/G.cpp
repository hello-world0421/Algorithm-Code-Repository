#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5 + 5; // 根据数据量权定
ll n, m, k;
ll a[N];
// 基于最小堆实现的优先队列（时间复杂度：n * logn）
// 优先队列的每次 pop 和 push 的时间复杂度为 logn
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i]); // 向队列中添加元素
        if (q.size() > k)
        {
            sum += q.top(); // 返回但不移除队列顶部的元素
            q.pop(); // 移除并返回队列顶部的元素
        }
        if (sum >= m)
        {
            cout << i - 1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}