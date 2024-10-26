#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    int n, m; cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
    }
    cout << (s[(m - n + 1) % k] == '1' ? 2 : 1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}