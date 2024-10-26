/*
数论 : 暴力枚举
时间复杂度 O(logn*logm) , 其中均以 k 为底
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, m, a, b; cin >> n >> k >> m >> a >> b;
    if (n % m == 0) { cout << "0\n";  return; };
    if (k == 1) { cout << "-1\n"; return; };

    ll ans = LLONG_MAX, cost = 0;
    while (true) {
        ll base = n % m, p = 1;
        for (int i = 0; ; i++) {
            ll delta = (m - base) % m;
            if (delta < p) {
                ans = min(ans, cost + a * i);
                break;
            }
            base = base * k % m; p *= k;
        }
        if (n == 0)
            break;
        n /= k; cost += b;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}