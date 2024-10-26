/*
图论 + 乘法原理 + 拓扑 dp
时间复杂度 O(n + m + k) 存疑
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int head[MAXN], nxt[MAXN], to[MAXN], cnt;
int fhead[MAXN], fnxt[MAXN], fto[MAXN], fcnt; // 反图
int n, m, k;
int rd[MAXN], cd[MAXN], trd[MAXN], tcd[MAXN];
long long ansa[MAXN], ansb[MAXN], ans;

inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

// 链式前向星建图
inline void add_edge(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

inline void fadd_edge(int u, int v) {
    fnxt[++fcnt] = fhead[u];
    fhead[u] = fcnt;
    fto[fcnt] = v;
}

inline void dfs(int x) {
    if (trd[x] != 0)
        return;
    // 链式前向星图的遍历
    for (register int i = head[x]; i; i = nxt[i]) {
        ansa[to[i]] = (ansa[to[i]] + ansa[x]) % MOD;
        trd[to[i]]--;
        dfs(to[i]);
    }
}

inline void fdfs(int x) {
    if (tcd[x] != 0)
        return;
    for (register int i = fhead[x]; i; i = fnxt[i]) {
        ansb[fto[i]] = (ansb[fto[i]] + ansb[x]) % MOD;
        tcd[fto[i]]--;
        fdfs(fto[i]);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    // 正反建两次图
    for (register int i = 1; i <= m; i++) {
        int u, v;
        u = read(), v = read();
        add_edge(u, v);
        fadd_edge(v, u);
        rd[v]++, cd[u]++;
        trd[v]++, tcd[u]++;
    }

    for (register int i = 1; i <= n; i++) {
        if (rd[i] == 0)
            ansa[i] = 1, dfs(i);
        if (cd[i] == 0)
            ansb[i] = 1, fdfs(i);
        // 正反跑点权
    }

    for (register int i = 1; i <= n; i++)
        if (cd[i] == 0)
            ans += ansa[i];
    ans %= MOD;
    printf("%lld\n", ans);

    for (register int i = 1; i <= k; i++) {
        int op, u, v;
        long long tmp = ans;
        op = read(), u = read(), v = read();
        if (op == 1) {
            tmp = (tmp - (ansa[u] * ansb[v] % MOD) + MOD) % MOD;
            if (rd[v] == 1)
                tmp = (tmp + ansb[v]) % MOD;
            if (cd[u] == 1)
                tmp = (tmp + ansa[u]) % MOD;
        } else {
            tmp = (tmp + (ansa[u] * ansb[v] % MOD)) % MOD;
            if (rd[v] == 0)
                tmp = (MOD + tmp - ansb[v]) % MOD;
            if (cd[u] == 0)
                tmp = (MOD + tmp - ansa[u]) % MOD;
        }
        printf("%lld\n", tmp);
    }

    return 0;
}