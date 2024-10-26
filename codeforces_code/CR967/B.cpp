#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
    } else if (n % 2 == 0) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << ' ';
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}