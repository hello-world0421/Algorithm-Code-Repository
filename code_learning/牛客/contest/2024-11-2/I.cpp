#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    if (n <= 1) {
        std::cout << "No\n";
    } else if((n & 1) == 0) {
        std::cout << (n == 2 ? "Yes\n" : "No\n");
    } else {
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                std::cout << "No\n";
                return;
            }
        }
        std::cout << "Yes\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();
}