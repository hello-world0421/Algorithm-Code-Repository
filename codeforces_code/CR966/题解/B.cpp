#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<bool> vis(n + 2, false);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        if (i != 0 && !vis[a - 1] && !vis[a + 1]) {
            ok = false;
            continue;
        }
        vis[a] = true;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}