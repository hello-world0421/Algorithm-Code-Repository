#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    int hh = std::stoi(s.substr(0, 2)), mm = std::stoi(s.substr(3, 2));
    hh += (hh < 6 ? 24 : 0);
    std::cout
        << std::setw(2) << std::setfill('0') << hh
        << ':'
        << std::setw(2) << std::setfill('0') << mm
        << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}