#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    int k; std::cin >> k;
    int n = s.length();
    for (int i = 0; i < k; i++) {
        std::cout << s.substr(i % n) + s.substr(0, i % n) << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}