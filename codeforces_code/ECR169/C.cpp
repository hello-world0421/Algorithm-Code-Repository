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
        } else if (k > 0) {
            ans += (a[i] - a[i + 1] - k);
            k = 0;
        } else {
            ans += (a[i] - a[i + 1]);
        }
    }
    if (n & 1) {
        ans += a[n - 1];
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