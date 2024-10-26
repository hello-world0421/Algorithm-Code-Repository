#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, r, L, R; cin >> l >> r >> L >> R;
    if (l > R || L > r) {
        cout << 1 << '\n';
    } else if (r >= L || R >= l) {
        cout << min(r, R) - max(l, L) + (r == R ? 0 : 1) + (l == L ? 0 : 1) << '\n';
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