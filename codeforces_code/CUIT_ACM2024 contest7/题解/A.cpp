#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e4 + 1;
bitset<MAXN> vis;

void solve() {
    vis.reset();
    int y1, y2, n, temp; cin >> y1 >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp; vis.set(temp);
    }
    cin >> y2;
    int ans = 0;
    for (int i = y1; i <= y2; i++) if (!vis.test(i)) ans++;
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