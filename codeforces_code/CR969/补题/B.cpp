#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    int a, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a; ans = max(ans, a);
    }
    char op; int x, y;
    while (q--) {
        cin >> op >> x >> y;
        if (ans <= y && ans >= x) {
            op == '+' ? ans++ : ans--;
        }
        cout << ans << " \n"[q == 0];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}