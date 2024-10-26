#include <bits/stdc++.h>

constexpr int MAXN = 101;

bool adj[MAXN][MAXN];

int n;

void warshall() {
    for (int bridge = 1; bridge <= n; bridge++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] |= (adj[i][bridge] & adj[bridge][j]);
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    warshall();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cout << adj[i][j] << " \n"[j == n];
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}