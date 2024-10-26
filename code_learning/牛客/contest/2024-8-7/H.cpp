#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n; cin >> x >> n;
    cout << x - ((n - 1) / 2) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}