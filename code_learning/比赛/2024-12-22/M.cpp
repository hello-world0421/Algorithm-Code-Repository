#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, q; std::cin >> n >> q;
    std::vector<i64> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];
    i64 x, y;
    while (q--) {
        std::cin >> x >> y;
        i64 size = -1, l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid] <= y) {
                size = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        size++;
        i64 ans = -1; l = size + 1, r = n;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (pre[mid] <= x + pre[size]) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans == -1) {
            std::cout << 0 << '\n';
            continue;
        }
        std::cout << ans - size << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}