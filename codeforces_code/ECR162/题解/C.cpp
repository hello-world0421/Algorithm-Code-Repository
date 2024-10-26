#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), pre1(n + 1), pre2(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre1[i + 1] = pre1[i] + a[i];
        pre2[i + 1] = pre2[i] + (a[i] == 1 ? 2 : 1);
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--;
        ll res1 = pre1[r] - pre1[l];
        ll res2 = pre2[r] - pre2[l];
        cout << (res2 <= res1 && r - l >= 2 ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}