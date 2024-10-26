#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 1;

void solve() {
    int ans = 0;
    int l, r; cin >> l >> r;
    ans += log(l) * 2;
    for (int i = l + 1; i <= r; i++) {
        ans += (i / 3);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}