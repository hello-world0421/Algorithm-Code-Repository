#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    while (!a.empty() && a.back() == 0) a.pop_back();
    while (!a.empty() && a.front() == 0) a.erase(a.begin());
    if (a.empty()) {
        std::cout << "0\n"; return;
    }
    bool hasZero = false;
    for (auto& x : a) {
        hasZero |= x == 0;
    }
    std::cout << (hasZero ? 2 : 1) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}