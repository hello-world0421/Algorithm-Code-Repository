#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + m);
    for (int i = 0, p, ans; i < q; i++) {
        cin >> p;
        if (b[0] < p && b[1] > p)
            ans = (b[1] - b[0]) >> 1;
        else if (b[0] > p)
            ans = b[0] - 1;
        else
            ans = n - b[1];
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}