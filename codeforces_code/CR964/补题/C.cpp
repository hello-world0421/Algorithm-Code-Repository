/*
思维题
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, m; cin >> n >> s >> m;
    int l, r, last = 0;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        if (l - last >= s) {
            ok = true;
        }
        last = r;
    }
    if (m - r >= s) {
        ok = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}