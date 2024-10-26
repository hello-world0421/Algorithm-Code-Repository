#include <bits/stdc++.h>
using i64 = long long;

int n, m;

i64 ans;

void solve() {
    ans = 0;
    std::cin >> n >> m;
    std::string last, now;
    std::cin >> last;
    for (int i = 2; i <= n; i++) {
        std::cin >> now;
        for (int j = 0; j < m - 1; j++) {
            if (now[j] != 'p') continue;
            if (now[j + 1] == 'c' && last[j] == 'c' && last[j + 1] == 'c') ans++;
        }
        last = now;
    }

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}