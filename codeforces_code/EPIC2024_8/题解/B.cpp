/*
博弈
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (a == b || a == vector<int>(b.rbegin(), b.rend())) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}