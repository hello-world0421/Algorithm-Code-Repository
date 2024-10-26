#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0, cnt = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (temp == 0 && ok) cnt++;
        if (temp == 1) {
            ok = true;
            ans += cnt;
            cnt = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}