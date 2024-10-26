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
        int l = 0, r = m - 1, mid, res = -1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (b[mid] >= p)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        if (res == 0)
            ans = b[0] - 1;
        else if (res == -1)
            ans = n - b[m - 1];
        else
            ans = (b[res] - b[res - 1]) >> 1;
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