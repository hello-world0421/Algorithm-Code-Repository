#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n1, n2; cin >> n1 >> n2;
    if (n1 & 1) {
        cout << "NO\n";
    } else if (n1 >= 2 || n2 % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}