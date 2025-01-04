#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<i64> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    auto compute = [&](std::vector<i64> &points) {
        std::sort(points.begin(), points.end());
        return points[n / 2] - points[(n - 1) / 2] + 1; // 计算左右中位数的差值
    };

    std::cout << compute(x) * compute(y) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}