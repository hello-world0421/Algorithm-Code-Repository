#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 6 + 1;
int n, m, k;
bitset<MAXN> vis[MAXN];
int ans;

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) vis[i].reset();
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y; vis[x].set(y);
    }

    ans = k;
    auto dfs = [&](auto&& self, int k) -> void {
        ans = min(ans, k);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (vis[i].test(j)) {
            if (i > 1 && i < n) {
                // 向上跳
                if (vis[i + 1].test(j) && !vis[i - 1].test(j)) {
                    vis[i + 1].reset(j); vis[i].reset(j); vis[i - 1].set(j);
                    self(self, k - 1);
                    vis[i + 1].set(j); vis[i].set(j); vis[i - 1].reset(j);
                }

                // 向下跳
                if (vis[i - 1].test(j) && !vis[i + 1].test(j)) {
                    vis[i - 1].reset(j); vis[i].reset(j); vis[i + 1].set(j);
                    self(self, k - 1);
                    vis[i - 1].set(j); vis[i].set(j); vis[i + 1].reset(j);
                }
            }

            if (j > 1 && j < m) {
                // 向左跳
                if (vis[i].test(j + 1) && !vis[i].test(j - 1)) {
                    vis[i].reset(j + 1); vis[i].reset(j); vis[i].set(j - 1);
                    self(self, k - 1);
                    vis[i].set(j + 1); vis[i].set(j); vis[i].reset(j - 1);
                }

                // 向右跳
                if (vis[i].test(j - 1) && !vis[i].test(j + 1)) {
                    vis[i].reset(j - 1); vis[i].reset(j); vis[i].set(j + 1);
                    self(self, k - 1);
                    vis[i].set(j - 1); vis[i].set(j); vis[i].reset(j + 1);
                }
            }
        }
    };

    dfs(dfs, k);
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