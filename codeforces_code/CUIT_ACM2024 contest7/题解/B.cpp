/*
动态规划 : 使用单调队列优化
时间复杂度 : O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 5e5 + 2;
// 维护区间最小值的单调队列
int mindeque[MAXN], head, tail;
int n, m, a[MAXN], p[MAXN], now;
ll dp[MAXN];
vector<int> b[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 为了方便得到最终答案，可以令 a[n + 1] = 0，然后要求 [n + 1, n + 1] 里建一座基站，
    // 这样答案就是 dp[n + 1] 了
    a[++n] = 0;
    cin >> m;
    for (int i = 1; i <= n; i++) b[i].clear();
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        b[u].push_back(-v);
        b[v].push_back(u);
    }
    b[n].push_back(n); b[n].push_back(-n);

    now = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        for (int x : b[i]) if (x > 0 && x >= j) now++;
        while (now > 0 && j <= i) {
            for (int x : b[j]) if (x < 0 && -x <= i) now--;
            j++;
        }
        assert(now == 0);
        p[i] = j;
    }

    head = tail = 1;
    dp[1] = a[1];
    mindeque[tail++] = 0;
    mindeque[tail++] = 1;

    for (int i = 2; i <= n; i++) {
        int lim = p[i - 1] - 1;
        while (head < tail && mindeque[head] < lim) head++;
        dp[i] = dp[mindeque[head]] + a[i];
        while (head < tail && dp[mindeque[tail - 1]] >= dp[i]) tail--;
        mindeque[tail++] = i;
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}