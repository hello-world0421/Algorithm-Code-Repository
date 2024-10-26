#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x0, y0, k; cin >> x0 >> y0 >> k;
    if (k == 1) {
        cout << x0 << " " << y0 << '\n';
    } else if (k % 2 == 1) {
        cout << x0 << " " << y0 << '\n';
        for (int i = 1, x = 1; i < k; i += 2, x++) {
            cout << x0 + x << " " << y0 + x << '\n';
            cout << x0 - x << " " << y0 - x << '\n';
        }
    } else {
        for (int i = 0, x = 1; i < k; i += 2, x++) {
            cout << x0 + x << " " << y0 + x << '\n';
            cout << x0 - x << " " << y0 - x << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}