/*
dfs
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 3e5 + 1;
vector<int> adj[MAXN];
bool visit[MAXN];
// sun 数组表示其子树的大小
ll sun[MAXN];
// check 数组中为 true 的节点表示其子树中包含 x 点
bool check[MAXN];
int n, x, y;

ll dfs(int u) {
    visit[u] = true;
    sun[u] = 1;
    if (u == x) check[u] = true;

    for (int s : adj[u]) {
        if (!visit[s]) {
            sun[u] += dfs(s);
            check[u] |= check[s];
        }
    }
    return sun[u];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    cin >> n >> x >> y;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(y);

    ll find = 0;
    for (int s : adj[y]) {
        if (check[s] == true) {
            find = sun[y] - sun[s];
            break;
        }
    }

    ll ans = find * sun[x];
    cout << ans << '\n';

    return 0;
}