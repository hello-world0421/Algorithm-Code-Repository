#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n), b(m), c(n), temp(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int j = 0, k = 0;
    for (int i = 0, x; i < m; ++i) {
        std::cin >> x;
        x <= a[0] ? b[j++] = x : temp[k++] = x;
    }
    std::sort(b.begin(), b.begin() + j);
    std::sort(temp.begin(), temp.begin() + k, std::greater<int>());
    for (int ii = 0; ii < k; ii++) {
        b[j++] = temp[ii];
    }

    for (int i = 1; i <= m; i++) {
        int t = m / i, cnt = 0, end = 0; i64 ans = 0;
        while (t--) {
            end = cnt + i - 1;
            for (int j = 0; j < n; j++) {
                c[j] = 0;
                for (int k = cnt; k <= end; k++) {
                    if (a[j] >= b[k]) c[j]++;
                }
            }
            cnt = end + 1;
            i64 res = 1;
            for (int j = 1; j < n; j++) {
                if (c[j] > c[0]) res++;
            }
            ans += res;
        }
        std::cout << ans << " \n"[i == m];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}