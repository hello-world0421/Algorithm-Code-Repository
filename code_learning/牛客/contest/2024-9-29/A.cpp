#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    std::cout << s[1] << s[0] << s.substr(2);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}