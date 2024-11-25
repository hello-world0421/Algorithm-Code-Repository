#include <bits/stdc++.h>

void solve() {
    std::vector<int> a;
    a.push_back(0);
    int n;
    while (std::cin >> n) {
        a.push_back(n);
    }
    n = a.size() - 1;

    auto process = [&](bool is_non_increasing) {
        std::vector<int> ends;
        auto comp = is_non_increasing
            ? [](int a, int b) { return a >= b; }
        : [](int a, int b) { return a < b; };

        for (int i = 1; i <= n; i++) {
            auto pos = std::lower_bound(ends.begin(), ends.end(), a[i], comp);
            if (pos == ends.end()) {
                ends.push_back(a[i]);
            } else {
                *pos = a[i];
            }
        }
        return ends.size();
    };

    std::cout << process(true) << '\n';
    std::cout << process(false) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}