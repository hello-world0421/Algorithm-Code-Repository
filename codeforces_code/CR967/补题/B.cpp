#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (!(n & 1)) {
        cout << -1 << '\n';
    } else {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        for (int i = 0; i + 1 < n; i += 2) {
            swap(p[i], p[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
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