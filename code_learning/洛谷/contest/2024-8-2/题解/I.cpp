/*
位运算 + 组合数学
时间复杂度 O(tlogn)
*/
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;

    int cnt = 0;
    while ((1ll << cnt) < n)
        cnt++;

    ll res = 0, nw = 1;
    for (int i = 0; i <= cnt; i++) {
        ll d = min(n, nw);
        res += d * i, n -= d;
        nw = nw * (cnt - i) / (i + 1);
    }
    cout << cnt << ' ' << res << endl;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}