// G题
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> hp(n + 1), ep(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> hp[i];
    }
    std::vector<std::vector<int>> gong(n + 1, std::vector<int>(n + 1, 0));

    auto operation = [&](int owner, int type, int cost, int target) {
        if (hp[owner] <= 0) return;

        if (type == 'P') {
            ep[owner]++;
        } else if (type == 'D') {
            if (ep[owner] >= cost) {
                ep[owner] -= cost; dp[owner] = cost + 2;
            } else {
                ep[owner] = 0; hp[owner]--;
            }
        } else if (type == 'A') {
            if (ep[owner] >= cost) {
                ep[owner] -= cost; gong[owner][target] = cost;
            } else {
                ep[owner] = 0; hp[owner]--;
            }
        } else if (type == 'E') {
            if (ep[owner] >= cost) {
                ep[owner] -= cost;
                for (int i = 1; i <= n; i++) {
                    if (i != owner) gong[owner][i] = (cost >> 1);
                }
            } else {
                ep[owner] = 0; hp[owner]--;
            }
        }
    };

    auto attack = [&](int i, int j) {
        if (gong[i][j] == 0) return;

        if (gong[j][i] == 0) {
            if (dp[j] > 0) {
                if (dp[j] >= gong[i][j]) {
                    dp[j] -= gong[i][j];
                } else {
                    hp[j] -= gong[i][j] - dp[j]; dp[j] = 0;
                }
            } else {
                hp[j] -= gong[i][j];
            }
            gong[i][j] = 0;
        } else {
            if (gong[i][j] > gong[j][i]) {
                hp[j] -= gong[i][j] - gong[j][i];
            } else {
                hp[i] -= gong[j][i] - gong[i][j];
            }
            gong[i][j] = 0; gong[j][i] = 0;
        }
    };

    while (m--) {
        for (int i = 1; i <= n; i++) {
            char type; std::cin >> type;
            int k = 0, x = 0;
            if (type == 'D' || type == 'E' || type == 'A') {
                std::cin >> k;
                if (type == 'A') std::cin >> x;
            }
            operation(i, type, k, x);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                attack(i, j);
            }
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
        }
    }

    i64 cnt = 0, ans = -1;
    for (int i = 1; i <= n; i++) {
        if (hp[i] > 0) {
            cnt++; ans = i;
        }
    }
    
    if (cnt == 1) {
        std::cout << ans << '\n';
    } else if (cnt == 0) {
        std::cout << "draw\n";
    } else if (cnt > 1) {
        std::cout << "continue\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}