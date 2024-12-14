// B题
#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<bool> b(m, false);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0, t; i < m; i++) {
        std::cin >> t; t--;
        b[t] = true;
    }

    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (!b[i] && (max_index == -1 || a[i] > a[max_index])) {
            max_index = i;
        }
    }

    std::cout << max_index + 1 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}