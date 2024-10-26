#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, r; cin >> l >> r;
    int L, R; cin >> L >> R;
    int maxN = max(r, R), minN = min(l, L);
    if (r < L || R < l) {
        cout << 1 << '\n';
    } else {
        cout << min(R, r) - max(L, l) + (r != R ? 1 : 0) + (l != L ? 1 : 0) << '\n';
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