#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    char ch; std::cin >> ch;
    int ans = 0, cnt = (int)std::sqrt((n + 1) / 2);
    ans = n - (cnt * cnt * 2 - 1);
    for (int i = 0; i < 2 * cnt - 1; i++) {
        if (i < cnt) {
            for (int j = 0; j < i; j++) {
                std::cout << ' ';
            }
            for (int j = 0; j < 2 * (cnt - i) - 1; j++) {
                std::cout << ch;
            }
            for (int j = 0; j < i; j++) {
                std::cout << ' ';
            }
            std::cout << '\n';
        } else {
            for (int j = 0; j < cnt - i + 1; j++) {
                std::cout << ' ';
            }
            for (int j = 0; j < 2 * (i - cnt + 1) + 1; j++) {
                std::cout << ch;
            }
            for (int j = 0; j < cnt - i + 1; j++) {
                std::cout << ' ';
            }
            std::cout << '\n';
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}