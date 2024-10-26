#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    int l = 0, r = b, ans = -1, mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (1ll * mid * (mid + 1) <= (b - a) * 2) {
            ans = mid; l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans + 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}