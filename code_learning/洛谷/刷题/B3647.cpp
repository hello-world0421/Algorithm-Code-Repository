#include <bits/stdc++.h>

#define INF INT_MAX
constexpr int MAXN = 101;

int dist[MAXN][MAXN];

int n, m;

void Floyd() {
    for (int bridge = 1; bridge <= n; bridge++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][bridge] != INF && dist[bridge][j] != INF && dist[i][j] > dist[i][bridge] + dist[bridge][j])
                    dist[i][j] = dist[i][bridge] + dist[bridge][j];
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i != j ? INF : 0);
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        dist[u][v] = std::min(w, dist[u][v]);
        dist[v][u] = std::min(w, dist[v][u]);
    }
    Floyd();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cout << dist[i][j] << " \n"[j == n];
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}