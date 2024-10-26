#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    x = (x + k - 1) / k, y = (y + k - 1) / k;
    cout << max(x, y) * 2 - ((x > y) ? 1 : 0) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}