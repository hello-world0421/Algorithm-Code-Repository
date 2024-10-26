#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1001;

void solve() {
    int l, r; cin >> l >> r;
    ll ans = 0;
    for (int i = l + 1; i + 1 <= r;) {
        if (i & 1) i++;
        else { ans++; i += 4; };
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}