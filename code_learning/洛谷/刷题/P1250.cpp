#include <bits/stdc++.h>

constexpr int MAXN = 3e4 + 1;

constexpr int MAXM = 95004;

int head[MAXN], next[MAXM], to[MAXM], weight[MAXM], cnt;

constexpr int MAXQ = 2e7 + 1;

int dist[MAXN], update[MAXN], queue[MAXQ], h, t;

bool enter[MAXN];

int n, m;

void prepare() {
    cnt = 1;
    h = t = 0;
    for (int i = 0; i <= n; i++) {
        head[i] = 0;
        dist[i] = INT_MIN;
        update[i] = 0;
        enter[i] = false;
    }
}

void addEdge(int u, int v, int w) {
    to[cnt] = v;
    weight[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}

bool spfa(int s) {
    dist[s] = 0;
    enter[s] = true;
    queue[t++] = s;
    update[s] = 1;
    while (h < t) {
        int u = queue[h++];
        enter[u] = false;
        for (int ei = head[u], v, w; ei > 0; ei = next[ei]) {
            v = to[ei];
            w = weight[ei];
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!enter[v]) {
                    if (++update[v] > n) {
                        return true;
                    }
                    queue[t++] = v;
                    enter[v] = true;
                }
            }
        }
    }
    return false;
}

void solve() {
    std::cin >> n >> m;
    prepare();
    for (int i = 1; i <= n; i++) {
        addEdge(0, i, 0);
    }
    for (int i = 1; i <= n; i++) {
        addEdge(i - 1, i, 0);
        addEdge(i, i - 1, -1);
    }
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        addEdge(u - 1, v, w);
    }
    spfa(0);
    std::cout << dist[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}