#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    std::string grid[n];
    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (grid[i][j] == 'p' && grid[i - 1][j] == 'c' && grid[i - 1][j + 1] == 'c' && grid[i][j + 1] == 'c') ans++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}