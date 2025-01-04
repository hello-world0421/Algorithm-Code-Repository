#include <bits/stdc++.h>

const std::string test = "xixixixi.";

void solve() {
    std::string s;

    while (std::cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            std::cout << s[i];
            if (s[i] == '.') std::cout << test;
        }
        std::cout << ' ';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}