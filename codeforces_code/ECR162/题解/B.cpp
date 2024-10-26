#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1), dis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int d;
    for (int i = 1; i <= n; i++) {
        cin >> d;
        dis[abs(d)] += a[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dis[i];
        if (sum > 1ll * i * k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}