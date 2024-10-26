#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (auto ch : s) {
        ans += ch - '0';
    }
    cout << ans << '\n';
}

int main() {
    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}