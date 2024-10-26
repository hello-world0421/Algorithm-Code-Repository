#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        if (a[i] - a[i + 1] <= k) {
            k -= (a[i] - a[i + 1]);
        } else {
            ans += (a[i] - a[i + 1] - k);
            k = 0;
        }
    }
    cout << ans + (n & 1 ? a[n - 1] : 0) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}