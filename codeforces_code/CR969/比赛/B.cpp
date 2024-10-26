#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;

void solve() {
    cin >> n >> m;
    ll ans = INT_MIN, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = max(ans, a);
    }
    char ch; ll l, r;
    for (int i = 0; i < m; i++) {
        cin >> ch >> l >> r;
        if (ans >= l && ans <= r)
            ch == '+' ? ans++ : ans--;
        cout << ans << " \n"[i == m - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}