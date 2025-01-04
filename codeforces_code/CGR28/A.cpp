#include <bits/stdc++.h>

void solve() {
    int x; std::cin >> x;
    bool ok = false;
    while (x > 0) {
        if (x % 33 == 0) {
            ok = true; break;
        }
        std::string s = std::to_string(x);
        auto it = s.find("33");
        if (it != std::string::npos) {
            s = s.substr(0, it) + s.substr(it + 2);
        } else {
            ok = false; break;
        }
        x = std::stoi(s);
    }
    std::cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}