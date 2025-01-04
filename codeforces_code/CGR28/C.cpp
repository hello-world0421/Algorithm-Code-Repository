#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s; s = "#" + s;
    int l1 = 1, r1 = s.size() - 1, l2 = 1, r2 = 1, aim = 2, cnt = 1;
    while (s[aim] == '1' && aim < s.size()) aim++;
    if (aim >= s.size()) aim--;
    while (aim + cnt <= s.size()) {
        std::string subs = s.substr(aim, cnt++);
        std::string oxs = "";
        for (int i = 0; i < subs.size(); i++) {
            oxs += subs[i] ^ 1;
        }
        auto it = s.find(oxs);
        if (it != std::string::npos && it <= aim) {
            l2 = it;
            r2 = it + s.size() - aim - 1;
        } else {
            break;
        }
    }
    std::cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}