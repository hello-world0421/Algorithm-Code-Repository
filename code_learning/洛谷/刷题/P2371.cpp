#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<i64, int>;

constexpr int MAXN = 13;

constexpr int MAXV = 5e5 + 1;

constexpr int MAXM = 10 * MAXV;

int n;

int a[MAXN], x;

i64 l, r;

int head[MAXV], next[MAXM], to[MAXM], cnt;

i64 weight[MAXM];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;

i64 distance[MAXV];

bool visit[MAXV];

void prepare() {
    cnt = 1;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> empty_heap;
    heap.swap(empty_heap);
    for (int i = 0; i < x; i++) {
        head[i] = 0;
        distance[i] = LLONG_MAX;
        visit[i] = false;
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
        if (visit[u]) continue;
        visit[u] = true;
        for (int ei = head[u], v; ei > 0; ei = next[ei]) {
            v = to[ei];
            if (!visit[v] && distance[v] > w + weight[ei]) {
                distance[v] = w + weight[ei];
                heap.push({ distance[v], v });
            }
        }
    }
}

i64 compute() {
    dijkstra();
    i64 ans = 0;
    for (int i = 0; i < x; i++) {
        if (distance[i] <= r)
            ans += (r - distance[i]) / x + 1;
        if (distance[i] <= l)
            ans -= (l - distance[i]) / x + 1;
    }
    return ans;
}

void solve() {
    std::cin >> n >> l >> r; l--;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 0) { i--, n--; }
    }
    std::sort(a, a + n);
    x = a[0];
    prepare();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < x; j++) {
            addEdge(j, (j + a[i]) % x, a[i]);
        }
    }
    std::cout << compute() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}