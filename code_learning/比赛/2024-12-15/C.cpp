#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        (b <= c ? b : c) += a[i];
    }
    std::cout << std::max(b, c) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}