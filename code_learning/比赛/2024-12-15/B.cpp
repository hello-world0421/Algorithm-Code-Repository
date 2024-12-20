#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s; std::cin >> s;
    i64 ans = LLONG_MAX, cnt = 0;

    for (char i = 'a'; i <= 'z'; i++) {
        cnt = 0;
        for (int j = 0, step; j < s.size(); j++) {
            step = ((s[j] - i) + 26) % 26;
            cnt += std::min(step, 26 - step);
        }
        ans = std::min(ans, cnt);
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}