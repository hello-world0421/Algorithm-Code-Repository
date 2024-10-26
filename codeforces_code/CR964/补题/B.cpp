/*
思维题
时间复杂度 O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 2 * (((a1 > b1) + (a2 > b2) > (a1 < b1) + (a2 < b2)) + ((a1 > b2) + (a2 > b1) > (a1 < b2) + (a2 < b1)));
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}