#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    if (s.size() >= 3 && s[0] == '1' && s[1] == '0' && s[2] != '0' && std::stoi(s.substr(2)) >= 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}