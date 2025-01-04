#include <bits/stdc++.h>

void solve() {
    int n, m = -1, c = -1; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) {
        std::cin >> x;
    }

    // 判断是否所有元素全部相等
    if (std::all_of(a.begin(), a.end(), [first = a.front()](int x) { return x == first; })) {
        std::cout << "0\n"; return;
    }

    // 判断是否存在相邻元素相等
    if (std::adjacent_find(a.begin(), a.end()) != a.end()) {
        std::cout << "-1\n"; return;
    }

    for (int i = 0; i < n - 1; i++) if (a[i] < a[i + 1]) {
        if (c == -1) c = a[i + 1] - a[i];
        else if (c != a[i + 1] - a[i]) {
            std::cout << "-1\n"; return;
        }
    }
    for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) {
        if (m == -1) m = a[i] + c - a[i + 1];
        else if (m != a[i] + c - a[i + 1]) {
            std::cout << "-1\n"; return;
        }
    }

    if (m == -1 || c == -1) {
        std::cout << "0\n"; return;
    }
    if (a[0] != a[0] % m) {
        std::cout << "-1\n"; return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != (a[i - 1] + c) % m) {
            std::cout << "-1\n"; return;
        }
    }
    std::cout << m << ' ' << c << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}