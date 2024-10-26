#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 5e5 + 1;

int v[MAXN];

i64 dist[MAXN];

int n, x;

i64 l, r;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

i64 compute() {
    std::sort(v + 1, v + 1 + n);
    x = v[1];
    for (int i = 0; i < x; i++)
        dist[i] = LLONG_MAX;
    dist[0] = 0;
    for (int i = 2, d; i <= n; i++) {
        d = gcd(v[i], x);
        for (int j = 0; j < d; j++) {
            for (int cur = j, next, circle = 0; circle < 2; circle += cur == j ? 1 : 0) {
                next = (cur + v[i]) % x;
                if (dist[cur] != LLONG_MAX) {
                    dist[next] = std::min(dist[next], dist[cur] + v[i]);
                }
                cur = next;
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i < x; i++) {
        if (r >= dist[i])
            ans += (r - dist[i]) / x + 1;
        if (l >= dist[i])
            ans -= (l - dist[i]) / x + 1;
    }

    return ans;
}

void solve() {
    std::cin >> n >> l >> r; l--;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        if (v[i] == 0) { i--, n--; }
    }
    if (n == 0) { std::cout << 0 << '\n'; return; }
    std::cout << compute() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}