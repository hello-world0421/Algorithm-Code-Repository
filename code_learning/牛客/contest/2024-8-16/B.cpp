#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int l, r; cin >> l >> r;
    ll ans = 0, k = 0;
    if (sum / n >= l && sum / n <= r) {
        for (int i = 0; i < n; i++) {
            if (a[i] > r) {
                ans += a[i] - r;
                k += a[i] - r;
            } else if (a[i] < l) {
                ans += l - a[i];
                k -= l - a[i];
            }
        }
        cout << 2 * ans - k << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}