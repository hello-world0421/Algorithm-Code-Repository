#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s; std::cin >> s;
    int n = s.size();
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    i64 b = a[0], cnt = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != b) cnt++;
        else if (cnt >= 2) {
            ans += (cnt * (cnt - 1) >> 1); cnt = 1;
        }
        b = a[i];
    }
    if (cnt >= 2) ans += (cnt * (cnt - 1) >> 1);
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}