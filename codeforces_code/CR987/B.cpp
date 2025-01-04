#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] - a[i + 1] == 1) {
                ok = true;
                std::swap(a[i], a[i + 1]);
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ans = false; break;
        }
    }
    std::cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}