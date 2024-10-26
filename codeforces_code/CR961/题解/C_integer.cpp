// 关键就是如何处理溢出情况，该段代码的思路类似爬山，对于每一个值都不会累乘
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> v;

void solve()
{
    // 输入信息
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;

    // 特判
    for (int i = 1; i < n; i++)
        if (v[i - 1] > 1 && v[i] == 1)
        {
            cout << "-1\n";
            return;
        }

    // 记录将 i 变成公平所需要的次数
    vector<ll> ops(n, 0);
    for (int i = 1; i < n; i++)
    {
        // 将数组中的数据取出，并不会改变数组中的数
        ll him = v[i - 1];
        ll me = v[i];
        ll extra = 0;
        while (him != 1 && him * him <= me)
            extra--, him *= him;
        while (me < him)
            extra++, me *= me;
        ops[i] = max(0ll, ops[i - 1] + extra);
    }

    // 输出结果
    ll ans = 0;
    for (auto i : ops)
        ans += i;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}