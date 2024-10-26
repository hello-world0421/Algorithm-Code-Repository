#include <bits/stdc++.h>

constexpr int MAXN = 1e3 + 2;

constexpr int MAXM = 3e3 + 1;

constexpr double sml = 1e-10;

constexpr double INF = 1e10;

// 二分答案法需要
double l, r, ans, mid;

// 链式前向星需要
int head[MAXN], next[MAXM], to[MAXM], cnt;

double weight[MAXM];

constexpr int MAXQ = 1e6 + 1;

// 誓言记录 [誓言类型, u, v, k]
// 得分记录 [u, w]
int flag[MAXN][4], score[MAXN][2];

// spfa 需要
int update[MAXN], queue[MAXQ], h, t;

double dist[MAXN];

bool enter[MAXN];

int n, m1, m2;

// 初始化链式前向星和 spfa
void prepare() {
    cnt = 1;
    h = t = 0;
    for (int i = 0; i <= n + 1; i++) {
        head[i] = 0;
        dist[i] = INF;
        update[i] = 0;
        enter[i] = false;
    }
}

// 链式前向星建边
void addEdge(int u, int v, double w) {
    to[cnt] = v;
    weight[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}

bool spfa(int s) {
    dist[s] = 0;
    update[s] = 1;
    queue[t++] = s;
    enter[s] = true;
    while (h < t) {
        int u = queue[h++];
        enter[u] = false;
        for (int ei = head[u], v; ei > 0; ei = next[ei]) {
            v = to[ei];
            double w = weight[ei];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!enter[v]) {
                    if (++update[v] > n + 1) {
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

// 是否有人穿女装
bool check(double limit) {
    prepare();
    // 0号点是连通超级源点，保证图的连通
    for (int i = 1; i <= n; i++) {
        addEdge(0, i, 0);
    }
    // 被杀关系建边
    for (int i = 1; i <= m1; i++) {
        if (flag[i][0] == 1) {
            addEdge(flag[i][1], flag[i][2], -log(-limit + flag[i][3]));
        } else {
            // 因为类型 2 的誓言是 < 关系，所以减去最小精度后，就可以认为是 <= 关系
            addEdge(flag[i][1], flag[i][2], log(limit + flag[i][3] - sml));
        }
    }
    // n + 1号点为限制超级源点，保证确定得分的选手之间的关系
    for (int i = 1; i <= m2; i++) {
        addEdge(n + 1, score[i][0], log(score[i][1]));
        addEdge(score[i][0], n + 1, -log(score[i][1]));
    }
    // 跑最短路是保证最大可能值
    // 有负环说明不存在解使得所有人不穿女装
    // return true 说明有负环，即有人穿女装
    return spfa(0);
}

// 二分答案法
double compute() {
    // 数据保证 k 的最大值就为 10
    l = 0, r = 10, ans = 0;
    // 单调性：ans 值越大穿女装的人越少
    while (r - l >= sml) {
        mid = (r + l) / 2;
        if (check(mid)) {
            ans = mid; l = mid + sml;
        } else {
            r = mid - sml;
        }
    }
    return ans;
}

void solve() {
    std::cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        std::cin >> flag[i][0] >> flag[i][1] >> flag[i][2] >> flag[i][3];
    }
    for (int i = 1; i <= m2; i++) {
        std::cin >> score[i][0] >> score[i][1];
    }
    double ans = compute();
    std::cout << (ans == 0 ? -1 : ans) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}