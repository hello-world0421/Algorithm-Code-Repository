/*
构造 + 前缀和
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    ll pre = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (i <= m)
            a[i] = 2 * i - 1;
        else
            pre -= a[i - m], a[i] = i * i - pre;
            // 因为 i * i 可能对于 int 会溢出
        pre += a[i];
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

int main()
{
    solve();
    return 0;
}