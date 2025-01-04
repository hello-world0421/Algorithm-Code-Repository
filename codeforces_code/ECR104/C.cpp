#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    if (n & 1) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (j - i <= n >> 1)
                    std::cout << 1 << ' ';
                else
                    std::cout << -1 << ' ';
    } else {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (j - i < n >> 1)
                    std::cout << 1 << ' ';
                else if (j - i == n >> 1)
                    std::cout << 0 << ' ';
                else
                    std::cout << -1 << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}