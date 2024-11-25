#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 ans = -1;
    for (i64 i = 3e4, res; i * i <= 1e10; i++) {
        res = i * i;
        std::vector<bool> vis(10, false);
        while (res > 0) {
            vis[res % 10] = true;
            res /= 10;
        }
        bool ok = true;
        for (int i = 0; i < 10; i++) {
            if (!vis[i]) ok = false;
        }
        if (ok) ans = std::max(ans, i * i);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}