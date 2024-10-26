#include <bits/stdc++.h>
using i64 = long long;

constexpr long double PI = 3.14159265358979324;

struct cir {
    i64 x, y, r;
    double dis;
    void compute() {
        if (in()) {
            dis = PI * r * r * (r - std::sqrt(x * x + y * y));
        } else {
            dis = 1e17;
        }
    }

    bool in() {
        return x * x + y * y < r * r;
    }

    bool friend operator < (cir a, cir b) {
        return a.dis < b.dis;
    }
};


void solve() {
    int n, k;
    std::cin >> n >> k;
    cir c[n], cn[n];
    for (int i = 0; i < n; i++) {
        std::cin >> c[i].x >> c[i].y >> c[i].r;
        c[i].compute();
    }
    i64 cnt = 0;
    for (int i = 0; i < n; i++) {
        if (c[i].in()) {
            cn[cnt++] = c[i];
        }
    }
    std::sort(cn, cn + cnt);
    long double ans = 0;
    for (int i = 0; i < cnt - k; i++) {
        ans += cn[i].dis;
    }
    std::cout << std::fixed << std::setprecision(17) << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}