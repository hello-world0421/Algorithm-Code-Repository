#include <bits/stdc++.h>

char map[9][9];

void solve() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cin >> map[i][j];
        }
    }
    char ans = '#';
    for (int i = 1; i <= 8; i++) {
        bool flag = true;
        for (int j = 1; j <= 8; j++) {
            if (map[i][j] != 'R') {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = 'R';
            break;
        }
    }
    for (int j = 1; j <= 8; j++) {
        bool flag = true;
        for (int i = 1; i <= 8; i++) {
            if (map[i][j] != 'B') {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = 'B';
            break;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}