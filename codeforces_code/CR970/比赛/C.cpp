#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int i = l, j = 1; i <= r; i += j++) {
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}