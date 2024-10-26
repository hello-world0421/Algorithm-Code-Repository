/*
map + 优先队列
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int MAXN = 1e5 + 1;

// 储存原始数据
int g, n, A[MAXN][2];

// M[i] 表示第 i 项工程还有几条要求未满足
int M[MAXN];

// B[i] 表示第 i 项工程的奖励
vector<pii> B[MAXN];

// C++ 中优先队列默认是按照大根堆进行排序的
// mp[i] 是一个按人数排序的小根堆，维护了与工种 i 有关的未满足需求
// mp[i] = {{j, k}, ... , }
// j 表示第 k 个工程所需要的工种 i 的数量
unordered_map<int, priority_queue<pii, vector<pii>, greater<pii>>> mp;

// have[i] 表示公司现有工种 i 的员工数量
unordered_map<int, ll> have;

queue<int> q;

// 公司增加工种 t 的员工共 u 名
void add(int t, int u) {
    ll& val = have[t];
    val += u;
    priority_queue<pii, vector<pii>, greater<pii>>& pq = mp[t];
    // 看哪些和工种 t 有关的需求被满足了
    while (!pq.empty()) {
        pii p = pq.top();
        if (p.first > val) break;
        pq.pop();
        // 如果工程所有要求都被满足，压入队列
        if (--M[p.second] == 0) q.push(p.second);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> g; assert(g >= 1);
    for (int i = 1; i <= g; i++) {
        // 为什么不直接 add 进 have?
        // 因为 add 函数中除了将现有工种压进 have 的步骤外，还会将满足
        // 工程需求的工程压入队列
        cin >> A[i][0] >> A[i][1];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> M[i];
        for (int j = 1; j <= M[i]; j++) {
            int a, b; cin >> a >> b;
            mp[a].push(pii(b, i));
        }
        int K; cin >> K;
        for (int j = 1; j <= K; j++) {
            int c, d; cin >> c >> d;
            B[i].push_back(pii(c, d));
        }
    }

    // 把没有任何要求的工程加入队列
    for (int i = 1; i <= n; i++) if (M[i] == 0) q.push(i);
    // 加入公司一开始就有的员工
    for (int i = 1; i <= g; i++) add(A[i][0], A[i][1]);

    int ans = 0;
    // 类似拓扑排序，不断从队列中拿出工程，并获得奖励
    while (!q.empty()) {
        int idx = q.front(); q.pop();
        ans++;
        for (pii p : B[idx]) add(p.first, p.second);
    }
    cout << ans << '\n';

    return 0;
}