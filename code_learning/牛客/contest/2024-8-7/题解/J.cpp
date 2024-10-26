/*
LCA ( dfs + st表 )
时间复杂度 O(nlogn + 23qlogn)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int fath[MAXN][18], dep[MAXN], F[26];

// dfs
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1; fath[x][0] = fa;
    for (auto s : adj[x]) {
        if (s != fa) dfs(s, x);
    }
}

// LCA
int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 17; i >= 0; i--) {
        if (dep[fath[x][i]] >= dep[y]) x = fath[x][i];
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (fath[x][i] != fath[y][i]) x = fath[x][i], y = fath[y][i];
    }
    return fath[x][0];
}

void solve() {
    // 预处理 fibonacci 数列
    // 第 25 项就已经超过 1e5
    F[1] = 1; F[2] = 2;
    for (int i = 3; i <= 25; i++) F[i] = F[i - 1] + F[i - 2];

    int n, root, q; cin >> n >> root >> q;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(root, 0);
    // st表
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            fath[i][j] = fath[fath[i][j - 1]][j - 1];

    while (q--) {
        int x, k; cin >> x >> k;
        if (k >= 25 || x + F[k] > n) {
            cout << "0\n";
            continue;
        }
        int ans = x + F[k];
        for (int i = k + 1; x + F[i] <= n; i++) {
            ans = LCA(ans, x + F[i]);
        }
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    solve();

    return 0;
}