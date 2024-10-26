#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 0) {
        cout << 0 << '\n';
    } else {
        while (n != 1 && k-- != 0) {
            n = ((n + 1) >> 1);
        }
        cout << n << '\n';
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