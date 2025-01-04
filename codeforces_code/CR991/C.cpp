#include <bits/stdc++.h>

void solve() {
    std::string num; std::cin >> num;
    int res = 0, cnt2 = 0, cnt3 = 0;
    for (auto& ch : num) {
        res = (res + ch - '0') % 9;
        if (ch == '2') cnt2++;
        if (ch == '3') cnt3++;
    }
    for (int i = 0; i <= cnt2; i++) {
        for (int j = 0; j <= cnt3; j++) {
            if ((res + 2 * i % 9 + 6 * j % 9) % 9 == 0) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}