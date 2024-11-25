#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    if (n == 0) {
        std::cout << 0 << '\n';
        return;
    }
    bool np = n < 0;
    std::string sn = std::to_string(abs(n));
    std::string rsn = "";
    for (int i = sn.length() - 1, flag = 0; i >= 0; i--) {
        if (sn[i] == '0' && !flag) continue;
        flag = 1; rsn += sn[i];
    }
    std::cout << (np ? "-" : "") << rsn << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}