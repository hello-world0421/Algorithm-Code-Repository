#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    int ans = -1, res;
    for (int i = 1; i <= 10000; i++) {
        res = i * (i + 1) >> 1;
        if (res >= n) {
            ans = i; res = i * (i - 1) >> 1; break;
        }
    }
    int temp = n - res;
    if (ans & 1) {
        std::cout << ans + 1 - temp << '/' << temp << '\n';
    } else {
        std::cout << temp << '/' << ans + 1 - temp << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}