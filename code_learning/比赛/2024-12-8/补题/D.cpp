// D题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m, a, b, k; std::cin >> n >> m >> a >> b >> k;
    int max = std::max(n, m), min = std::min(n, m);

    std::function<int(int, int, int)> huihuan = [&](int x, int y, int b) {
        if (b == 0) return x;
        if (x == 0 || y == 0) return 0;
        return x + huihuan(y - 1, x, b - 1);
    };

    int max_cover = a >= min ? max * min : max * (a - 1) + huihuan(max, min - a + 1, b);
    if (max_cover < k) { std::cout << "NO\n"; return; }
    std::cout << "YES\n";

    // if (n * std::min(a, m) < k) {
    //     ...
    // } else {
    //     ...
    // }
    if (a >= min) {
        std::string direction = n > m ? "D" : "R";
        for (int i = 0, x = 1, y = 1; i < b; i++) {
            if (y % (m + 1) == 0) { x++; y = 1; }
            std::cout << x << ' ' << y << ' ' << direction << '\n';
            y++;
        }
        for (int i = 0, x = 1, y = 1; i < a; i++) {
            if (k >= max) {
                k -= max;
                std::cout << x << ' ' << y << ' ' << direction << '\n';
                x++;
            } else if (k > 0) {
                std::cout << x << ' ' << max - k + 1 << ' ' << direction << '\n';
                k = 0;
            } else {
                std::cout << 1 << ' ' << 1 << ' ' << direction << '\n';
            }
        }
    } else if (a * max >= k) {
        std::string direction = n > m ? "D" : "R";
        for (int i = 0, x = 1, y = 1; i < b; i++) {
            if (y % (m + 1) == 0) { x++; y = 1; }
            std::cout << x << ' ' << y << ' ' << direction << '\n';
            y++;
        }
        for (int i = 0, x = 1, y = 1; i < a; i++) {
            if (k >= max) {
                k -= max;
                std::cout << x << ' ' << y << ' ' << direction << '\n';
                x++;
            } else if (k > 0) {
                std::cout << x << ' ' << max - k + 1 << ' ' << direction << '\n';
                k = 0;
            } else {
                std::cout << 1 << ' ' << 1 << ' ' << direction << '\n';
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}