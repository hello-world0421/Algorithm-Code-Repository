#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 1;
vector<int> adj[MAXN];

void dfs(int n, int fa) {
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int n, x, y; cin >> n >> x >> y;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}