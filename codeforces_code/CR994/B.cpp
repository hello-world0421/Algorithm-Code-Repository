#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    if (s.front() == 's') s.front() = '.';
    if (s.back() == 'p') s.back() = '.';
    bool test = std::count(s.begin(), s.end(), 's') && std::count(s.begin(), s.end(), 'p');
    std::cout << (test ? "NO" : "YES") << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}