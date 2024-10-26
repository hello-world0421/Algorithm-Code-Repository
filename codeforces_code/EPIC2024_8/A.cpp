#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    cout << min(n, k) * min(m, k) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}