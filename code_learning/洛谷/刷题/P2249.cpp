#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 1;

int n, m, q;

int a[MAXN];

int l, r, ans, mid;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        l = 1, r = n, ans = -1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid] >= q) {
                if (a[mid] == q) ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}