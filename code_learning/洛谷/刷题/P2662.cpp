#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;

constexpr int MAXN = 101;

constexpr int MAXV = 3001;

constexpr int MAXM = 30001;

int head[MAXV], next[MAXM], to[MAXM], cnt;

i64 weight[MAXM];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;

i64 distance[MAXV];

bool visited[MAXV], used[MAXV];

int n, m, x, l[MAXN];

void prepare() {
    cnt = 1;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> empty_heap;
    heap.swap(empty_heap);
    for (int i = 0; i < x; i++) {
        head[i] = 0;
        distance[i] = LLONG_MAX;
        visited[i] = false;
        used[i] = false;
    }
}

void addEdge(int u, int v, i64 w) {
    to[cnt] = v;
    weight[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}

void dijkstra() {
    heap.push({ 0, 0 });
    distance[0] = 0;
    int u; i64 w;
    while (!heap.empty()) {
        auto [w, u] = heap.top(); heap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int ei = head[u], v; ei > 0; ei = next[ei]) {
            v = to[ei];
            if (!visited[v] && distance[v] > w + weight[ei]) {
                distance[v] = w + weight[ei];
                heap.push({ distance[v], v });
            }
        }
    }
}

i64 compute() {
    i64 ans = 0;
    if (x == 1) {
        ans = -1;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = std::max(1, l[i] - m); j <= l[i]; j++) {
                if (!used[j]) {
                    used[j] = true;
                    for (int k = 0; k < x; k++) {
                        addEdge(k, (k + j) % x, j);
                    }
                }
            }
        }
        dijkstra();
        for (int i = 0; i < x; i++) {
            if (distance[i] == LLONG_MAX) {
                ans = -1;
                break;
            }
            ans = std::max(ans, distance[i] - x);
        }
    }
    return ans;
}

void solve() {
    std::cin >> n >> m;
    x = INT_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
        x = std::min(x, std::max(1, l[i] - m));
    }
    prepare();
    std::cout << compute() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}