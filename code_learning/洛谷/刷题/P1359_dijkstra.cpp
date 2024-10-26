#include <bits/stdc++.h>
using pii = std::pair<int, int>;

constexpr int MAXN = 201;

std::vector<pii> adj[MAXN];

int distance[MAXN];

bool visit[MAXN];

int n;

void solve() {
    std::cin >> n;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        distance[i] = INT_MAX;
        visit[i] = false;
    }
    for (int i = 1, w; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            std::cin >> w;
            adj[i].push_back({ w, j });
        }
    }
    distance[1] = 0;
    heap.push({ 0, 1 });
    while (!heap.empty()) {
        int u = heap.top().second; heap.pop();
        if (visit[u]) continue;
        visit[u] = true;
        for (pii edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;
            if (!visit[v] && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                heap.push({ distance[v], v });
            }
        }
    }
    std::cout << distance[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}