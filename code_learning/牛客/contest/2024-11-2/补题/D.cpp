#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    int cnt = 0, ans = 0;
    for (int i = 0, score, credit; i < n; i++) {
        std::cin >> score >> credit;
        if (score < 60) {
            cnt++; ans += credit;
        }
    }
    std::cout << cnt << ' ' << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}