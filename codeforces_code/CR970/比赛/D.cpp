#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 1;
int to[MAXN], in[MAXN];
bool vis[MAXN], fo[MAXN];

void solve() {
    int n; cin >> n;
    memset(vis, false, sizeof(bool) * (n + 1));
    memset(in, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) cin >> to[i];
    string s; cin >> s; s = " " + s;
    vector<int> ans(n + 1, 0);
    auto dfs1 = [&](auto&& self, const int p, const int fa) -> void {
        if (!vis[p]) {
            vis[p] = true; fo[p] = true;
            ans[p] += (s[p] == '0' ? 1 : 0);
            if (fo[to[p]]) {
                ans[p] = ans[to[p]];
            }
            self(self, to[p], p);
            ans[fa] += ans[p];
        }
    };
    for (int i = 1; i <= n; i++) {
        memset(fo, false, sizeof(bool) * (n + 1));
        if (!vis[i]) {
            dfs1(dfs1, i, 0);
        }
    }
    // memset(vis, false, sizeof(bool) * (n + 1));
    // auto dfs2 = [&](auto&& self, const int p, const int fa) -> void {
    //     if (!vis[p]) {
    //         vis[p] = true;
    //         self(self, to[p], p);
    //         ans[fa] += ans[p];
    //     }
    // };
    // for (int i = 1; i <= n; i++) {
    //     if (!vis[i]) dfs2(dfs2, i, 0);
    // }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}