#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;

int n, m;

int a[MAXN], b[MAXN];

int l, r, ans, mid;

ll res;

void solve() {
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + m);

    res = 0;
    for (int i = 0; i < n; i++) {
        l = 0, r = m - 1, ans = m;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid] >= b[i]) {
                ans = mid; r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == 0 || ans == m) {
            res += (ans == 0 ? a[0] - b[i] : b[i] - a[m - 1]);
        } else {
            res += min(abs(a[ans] - b[i]), abs(a[ans - 1] - b[i]));
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}