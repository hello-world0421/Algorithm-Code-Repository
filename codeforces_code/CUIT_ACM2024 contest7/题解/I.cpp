#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 1;
int n, m;
// 将二维数组压缩成一维数组
int a[MAXN];
ll ans, l, r, mid;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i * m + j];

    auto check = [&](const ll& lim) {
        ll last = -1;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i * m + j] < lim) {
            if (last > j) return false;
            last = j;
        }
        return true;
    };

    l = 0, r = n * m, ans = -1;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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