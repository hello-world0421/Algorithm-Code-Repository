#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if ((i & 1) == 0) a.push_back(x); else b.push_back(x);
    }
    std::stable_sort(a.begin(), a.end());
    std::stable_sort(b.begin(), b.end());
    std::vector<int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
        if (i < b.size()) c.push_back(b[i]);
    }
    for (int i = 1; i < c.size(); i++) {
        if (c[i] < c[i - 1]) {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}