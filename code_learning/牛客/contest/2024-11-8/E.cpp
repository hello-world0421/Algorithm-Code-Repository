#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0, op, x, y; i < n; i++) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            a[i] = { x, 0 };
        } else {
            std::cin >> x >> y;
            a[i] = { x, y };
        }
    }
    
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}