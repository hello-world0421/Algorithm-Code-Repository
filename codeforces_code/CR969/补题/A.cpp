#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
    连续的两个数的 gcd 值一定为 1
    连续的两个奇数的 gcd 值一定为 1
    */
    int l, r; cin >> l >> r;
    int ans = ((((r + 1) >> 1) - (l >> 1)) >> 1);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}