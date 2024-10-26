#include <bits/stdc++.h>

constexpr int MAXN = 1e3 + 1;

constexpr int MAXM = 2e4 + 2e3 + 3;

int head[MAXN], next[MAXM], to[MAXM], weight[MAXM], cnt;

constexpr int MAXQ = 2e7 + 1;

int dist[MAXN], update[MAXN], queue[MAXQ], h, t;

bool enter[MAXN];

int n, m1, m2;

void prepare() {
    cnt = 1;
    for (int i = 0; i <= n; i++) {
        head[i] = 0;
    }
}

void addEdge(int u, int v, int w) {
    to[cnt] = v;
    weight[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}

int spfa(int s) {
    h = t = 0;
    for (int i = 0; i <= n; i++) {
        dist[i] = INT_MAX;
        update[i] = 0;
        enter[i] = false;
    }
    dist[s] = 0;
    update[s] = 1;
    queue[t++] = s;
    enter[s] = true;
    while (h < t) {
        int u = queue[h++];
        enter[u] = false;
        for (int ei = head[u], v, w; ei > 0; ei = next[ei]) {
            v = to[ei];
            w = weight[ei];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!enter[v]) {
                    if (++update[v] > n) {
                        return -1;
                    }
                    queue[t++] = v;
                    enter[v] = true;
                }
            }
        }
    }
    if (dist[n] == INT_MAX) {
        return -2;
    }
    return dist[n];
}

void solve() {
    std::cin >> n >> m1 >> m2;
    prepare();
    for (int i = 1, u, v, w; i <= m1; i++) {
        std::cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    for (int i = 1, u, v, w; i <= m2; i++) {
        std::cin >> u >> v >> w;
        addEdge(v, u, -w);
    }
    for (int i = 1; i <= n; i++) {
        addEdge(0, i, 0);
    }
    for (int i = 1; i < n; i++) {
        addEdge(i + 1, i, 0);
    }
    std::cout << (spfa(0) == -1 ? -1 : spfa(1)) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}