#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    ll dis = 1ll * (xs - xt) * (xs - xt) + 1ll * (ys - yt) * (ys - yt);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ll res = 1ll * (x[i] - xt) * (x[i] - xt) + 1ll * (y[i] - yt) * (y[i] - yt);
        if (res <= dis) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}