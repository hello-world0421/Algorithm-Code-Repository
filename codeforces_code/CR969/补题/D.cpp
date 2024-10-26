#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> deg(n + 1, 0);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    string s; cin >> s;
    int x = 0, y = 0, z = 0, w = 0;
    for (int i = 2; i <= n; i++) {
        if (deg[i] == 1) {
            if (s[i - 1] == '0') {
                x++;
            } else if (s[i - 1] == '1') {
                y++;
            } else if (s[i - 1] == '?') {
                z++;
            }
        } else if (s[i - 1] == '?') {
            w++;
        }
    }
    if (s[0] == '0') {
        cout << y + ((z + 1) >> 1) << '\n';
    } else if (s[0] == '1') {
        cout << x + ((z + 1) >> 1) << '\n';
    } else {
        cout << max(x, y) + (z + (x == y ? w & 1 : 0) >> 1) << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}