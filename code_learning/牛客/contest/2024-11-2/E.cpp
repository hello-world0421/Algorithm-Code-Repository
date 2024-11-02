#include <bits/stdc++.h>

const char colors[] = { 'B', 'R' };

void solve() {
    char map[9][9];
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cin >> map[i][j];
        }
    }
    char ans = '#';

    for (int i = 1; i <= 8; i++) {
        bool ok = true;
        for (int j = 1; j <= 8; j++) {
            if (map[i][j] != 'R') {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = 'R';
            break;
        }
    }
    for (int j = 1; j <= 8; j++) {
        bool ok = true;
        for (int i = 1; i <= 8; i++) {
            if (map[i][j] != 'B') {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = 'B';
            break;
        }
    }
    if (ans != '#') {
        std::cout << ans << '\n';
        return;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();
}