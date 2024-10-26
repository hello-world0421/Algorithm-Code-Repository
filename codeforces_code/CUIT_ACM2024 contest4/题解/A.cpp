#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    ll sum = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        sum += a[i].second;
        if (sum > 1ll * a[i].first * k) {
            ok = false;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}