#include <bits/stdc++.h>
using namespace std;
int y[101];

void solve() {
    int y1, y2, n;
    cin >> y1 >> n;
    if (n > 0)
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }
    cin >> y2;
    int ans = y2 - y1 + 1;
    if (n > 0)
        for (int i = 0; i < n; i++) if (y[i] <= y2 && y[i] >= y1) ans--;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}