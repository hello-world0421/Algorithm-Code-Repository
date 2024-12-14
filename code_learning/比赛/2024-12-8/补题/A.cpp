// A题
#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    for (int i = 0, a; i < n; i++) {
        std::cin >> a;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << i << " \n"[i == n];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}