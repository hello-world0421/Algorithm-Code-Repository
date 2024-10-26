#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<i64, int>;

constexpr int MAXN = 1e5 + 1;

constexpr int MAXM = MAXN * 2;

i64 h;

int a[3];

int head[MAXN], next[MAXM], to[MAXM], cnt;

i64 weight[MAXM];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;

i64 distance[MAXN];

bool visited[MAXN];

void prepare() {
    cnt = 1;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> emptyQueue;
    heap.swap(emptyQueue);
    for (int i = 0; i < a[0]; i++) {
        head[i] = 0;
        distance[i] = LLONG_MAX;
        visited[i] = false;
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
    int u;
    i64 w;
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
    dijkstra();
    i64 ans = 0;
    for (int i = 0; i < a[0]; i++) {
        if (distance[i] <= h) {
            ans += (h - distance[i]) / a[0] + 1;
        }
    }
    return ans;
}

void solve() {
    std::cin >> h >> a[0] >> a[1] >> a[2];
    h--; std::sort(a, a + 3);
    prepare();
    for (int i = 0; i < a[0]; i++) {
        addEdge(i, (i + a[1]) % a[0], a[1]);
        addEdge(i, (i + a[2]) % a[0], a[2]);
    }
    std::cout << compute() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}