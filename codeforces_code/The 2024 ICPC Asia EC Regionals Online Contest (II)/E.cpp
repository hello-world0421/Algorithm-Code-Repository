#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int N = 4e5 + 1;
int n, m, d, k, dis1[N], dis2[N], dis3[N], pre[N];
// dis1 记录杀手到每个点的最短距离
// dis2 记录玩家在没有杀手的情况下到每个点的最短距离
// dis3 记录玩家在有杀手的情况下到每个点的最短距离
// pre 记录最短路径
bool valid[N];
// valid 记录在有杀手的情况下每个点是否可达
vector<int> G[N];
queue<int> Q;

void BFS(queue<int>& Q, int dis[]) {
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int v : G[x]) {
            if (!valid[v]) continue;
            if (dis[v] > dis[x] + 1) {
                dis[v] = dis[x] + 1;
                pre[v] = x;
                Q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> d;
    for (int i = 1; i <= 2 * n; i++)
        G[i].clear(), dis1[i] = dis2[i] = dis3[i] = INF, valid[i] = 1;
    for (int i = 1, x, y, x1, x2, y1, y2; i <= m; i++) {
        cin >> x >> y;
        x1 = 2 * x - 1, y1 = 2 * y - 1;
        x2 = 2 * x, y2 = 2 * y;
        G[x1].push_back(y2); G[y2].push_back(x1);
        G[x2].push_back(y1); G[y1].push_back(x2);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int s; cin >> s;
        dis1[2 * s - 1] = 0;
        Q.push(2 * s - 1);
    }
    BFS(Q, dis1);
    Q.push(1); dis2[1] = 0;
    BFS(Q, dis2);

    for (int i = 1; i <= 2 * n; i++) {
        valid[i] = dis1[i] > d || dis2[i] < dis1[i];
    }

    if (!valid[1]) {
        cout << "-1\n"; return;
    }

    Q.push(1); dis3[1] = 0; pre[1] = -1;
    BFS(Q, dis3);
    if (min(dis3[2 * n - 1], dis3[2 * n]) == INF) {
        cout << "-1\n"; return;
    } else {
        cout << min(dis3[2 * n - 1], dis3[2 * n]) << '\n';
    }

    int x = (dis3[2 * n - 1] <= dis3[2 * n] ? 2 * n - 1 : 2 * n);
    vector<int> path;
    while (x != -1) path.push_back(x), x = pre[x];
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << (path[i] + 1) / 2 << " \n"[i == 0];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}