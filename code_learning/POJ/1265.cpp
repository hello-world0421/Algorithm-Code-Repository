#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>

void Pick(std::vector<std::pair<int, int>>& points, double& area, double& internal, double& boundary) {
    std::function<int(int, int)> gcd = [&](int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    };

    auto boundaryPoints = [&](int x1, int y1, int x2, int y2) {
        return gcd(abs(x1 - x2), abs(y1 - y2));
    };

    int n = points.size();
    area = 0, boundary = 0;
    for (int i = 0; i < n; i++) {
        int x1 = points[i].first, y1 = points[i].second;
        int x2 = points[(i + 1) % n].first, y2 = points[(i + 1) % n].second;
        area += x1 * y2 - x2 * y1;
        boundary += boundaryPoints(x1, y1, x2, y2);
    }
    area = abs(area) / 2;
    internal = area - boundary / 2 + 1;
}

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0, x = 0, y = 0, dx, dy; i < n; i++) {
        std::cin >> dx >> dy;
        x += dx, y += dy;
        points[i] = { x, y };
    }
    double area, internal, boundary;
    Pick(points, area, internal, boundary);
    std::cout << internal << ' ' << boundary << ' ' << std::fixed << std::setprecision(1) << area << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    for (int i = 1; i <= tt; i++) {
        std::cout.precision(0);
        std::cout << "Scenario #" << i << ":\n";
        solve();
        std::cout << '\n';
    }

    return 0;
}