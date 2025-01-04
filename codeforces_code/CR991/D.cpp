#include <bits/stdc++.h>

void solve() {
    std::string s; std::cin >> s;
    int n = s.size();
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }

    bool ok = true; int unsorted = n - 1;
    while (ok) {
        ok = false;
        for (int i = 0; i < unsorted; ++i) {
            if (a[i + 1] - 1 > a[i]) {
                a[i + 1]--;
                std::swap(a[i], a[i + 1]);
                ok = true;
            }
        }
        unsorted--;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}