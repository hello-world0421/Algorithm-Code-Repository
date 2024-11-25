#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n; std::cin >> n;
    std::vector<i64> a(n);
    i64 maxa = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        maxa = std::max(maxa, a[i]);
    }

    auto check = [&](i64 limit) {
        std::vector<i64> b(a);
        i64 minb;
        for (int i = 0; i < n; i++) {
            b[i] -= limit;
        }
        i64 k = limit;
        for (int i = 0; i < n - 1; i++) {
            if (k > 0 && b[i] > 0 && b[i + 1] > 0) {
                minb = std::min(b[i], b[i + 1]);
                if (k >= minb) {
                    k -= minb; b[i] -= minb; b[i + 1] -= minb;
                } else {
                    b[i] -= k; b[i + 1] -= k; k = 0;
                    break;
                }
            }
        }
        i64 m = k + limit;
        for (int i = 0; i < n; i++) {
            if (m > 0 && b[i] > 0) {
                if (m >= b[i]) {
                    m -= b[i]; b[i] = 0;
                } else {
                    b[i] -= m; m = 0;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                return false;
            }
        }
        return true;
    };

    i64 l = 1, r = maxa, ans = -1, mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}