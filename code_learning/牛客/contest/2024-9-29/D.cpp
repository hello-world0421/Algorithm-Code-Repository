#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e5 + 1;

constexpr int mod = 1e9 + 7;

std::vector<int> adj[MAXN];

int deep[MAXN], pre[MAXN];

bool leaf[MAXN];

int n;

void dfs(int s, int fa) {
    deep[s] = deep[fa] + 1;
    if (adj[s].size() == 1 && s != 1) {
        leaf[s] = true;
    } else {
        i64 siz = adj[s].size() - (s != 1);
        for (int son : adj[s]) if (son != fa) {
            pre[son] = pre[s] * siz % mod;
            dfs(son, s);
        }
    }
}

i64 quickpow(i64 a, i64 k) {
    i64 ans = 1;
    while (k > 0) {
        if (k & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return ans;
}

void solve() {
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << '\n';
        return;
    }
    for (int i = 0; i <= n; i++) {
        pre[i] = 1;
    }
    for (int i = 0, u, v; i < n - 1; i++) {
        std::cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1, 0);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (leaf[i]) {
            ans = (ans + (deep[i] * quickpow(pre[i], mod - 2) % mod)) % mod;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}