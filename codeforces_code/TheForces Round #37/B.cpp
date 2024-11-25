#include <bits/stdc++.h>

constexpr int MAXN = 1e3 + 1;
char grid[MAXN][MAXN];

void solve() {
    int n, k; std::cin >> n >> k;
    const int row = ((n + 1) >> 1);
    int flag = row * row;
    if (k > flag || k > 26) {
        std::cout << -1 << '\n';
    } else {
        char ch = 'a'; k--;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= row; j++) {
                grid[i][j] = ch;
                if (k > 0) {
                    ch++; k--;
                }
            }
        }
        for (int i = 1; i <= row; i++) {
            for (int j = row + 1; j <= n; j++) {
                grid[i][j] = grid[i][n - j + 1];
            }
        }
        for (int i = row + 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j] = grid[n - i + 1][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cout << grid[i][j];
            }
            std::cout << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}