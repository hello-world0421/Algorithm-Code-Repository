#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int m; std::cin >> m;

    auto check = [&](const auto& s) {
        if (s.size() != n) {
            return false;
        }
        std::map<int, char> num;
        std::map<char, int> ch;
        for (int i = 0; i < n; i++) {
            if (!num.count(a[i]) && !ch.count(s[i])) {
                num[a[i]] = s[i], ch[s[i]] = a[i];
            } else if (num[a[i]] != s[i] || ch[s[i]] != a[i]) {
                return false;
            }
        }
        return true;
    };
    
    for (int i = 0; i < m; i++) {
        std::string s; std::cin >> s;
        std::cout << (check(s) ? "YES\n" : "NO\n");
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