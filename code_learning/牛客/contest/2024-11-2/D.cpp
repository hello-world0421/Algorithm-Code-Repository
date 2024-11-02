#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    int cnt = 0, ans = 0;
    for (int i = 0, grade, dict; i < n; i++) {
        std::cin >> grade >> dict;
        if (grade < 60) {
            cnt++; ans += dict;
        }
    }
    std::cout << cnt << ' ' << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}