#include <bits/stdc++.h>

constexpr double sml = 1e-13;

double l, r, mid, midmid, ans;

struct Point {
    double x, y;
};

Point points[3];

double s;

double func(double p) {
    return 3 * p * p - 3 * p + 1;
}

void solve() {
    std::cin >> l >> r;
    for (int i = 0; i < 3; i++) {
        std::cin >> points[i].x >> points[i].y;
    }
    std::vector<double> vec[2];
    for (int i = 0; i < 2; i++) {
        vec[i].push_back(points[i + 1].x - points[0].x);
        vec[i].push_back(points[i + 1].y - points[0].y);
    }
    s = abs(vec[0][0] * vec[1][1] - vec[1][0] * vec[0][1]) / 2;
    ans = -1;
    while (r - l >= sml) {
        mid = (r + l) / 2;
        midmid = (mid + r) / 2;
        if (func(mid) < func(midmid))
            ans = mid, r = midmid - sml;
        else
            ans = midmid, l = mid + sml;
    }
    std::cout << std::fixed << std::setprecision(12) << func(ans) * s << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}