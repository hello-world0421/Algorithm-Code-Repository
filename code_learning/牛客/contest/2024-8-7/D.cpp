#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n <= 2) {
        cout << (n == 2 ? "Yes\n" : "No\n");
        return;
    } else if (n % 2 == 0) {
        cout << "No\n";
        return;
    } else {
        for (int i = 3; i * i <= n; i++) {
            if (n % i == 0) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
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