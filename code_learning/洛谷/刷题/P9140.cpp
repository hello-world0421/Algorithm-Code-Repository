#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e5 + 1;

constexpr i64 inf = LLONG_MIN;

int v[MAXN], c[MAXN];

i64 dp[MAXN];

int n, m, x, y;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void compute() {
    for (int i = 0; i < x; i++)
        dp[i] = inf;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) if (v[i] != x)
        for (int j = 0, d = gcd(v[i], x); j < d; j++)
            for (int cur = j, next, circle = 0; circle < 2; circle += cur == j ? 1 : 0) {
                next = (cur + v[i]) % x;
                if (dp[cur] != inf)
                    dp[next] = std::max(dp[next], dp[cur] - (i64)((cur + v[i]) / x) * y + c[i]);
                cur = next;
            }
}

void solve() {
    std::cin >> n >> m;
    double best = 0, ratio;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i] >> c[i];
        ratio = (double)c[i] / v[i];
        if (ratio > best) {
            best = ratio;
            x = v[i];
            y = c[i];
        }
    }
    compute();
    i64 jobv;
    for (int i = 1, v; i <= m; i++) {
        std::cin >> jobv;
        v = (jobv % x);
        std::cout << (dp[v] == inf ? -1 : jobv / x * y + dp[v]) << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}