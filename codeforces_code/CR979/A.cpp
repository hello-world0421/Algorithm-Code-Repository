#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int max_val = *std::max_element(a.begin(), a.end());
    int min_val = *std::min_element(a.begin(), a.end());
    std::cout << (max_val - min_val) * (n - 1) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}