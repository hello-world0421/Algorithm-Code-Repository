#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    char map[2][n + 1];
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> map[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 'x') continue;
            int flag = 0;
            if (map[i ^ 1][j] == '.') flag++;
            if (j != 1 && map[i][j - 1] == '.') flag++;
            if (j != n && map[i][j + 1] == '.') flag++;
            if (flag == 0) {
                ans++;
                continue;
            } else if (flag >= 2) {
                
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}