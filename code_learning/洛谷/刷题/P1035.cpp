#include <bits/stdc++.h>

constexpr double gamma = 0.5772156649;

// double k, res, i;
int k;

int table[] = { 0, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675214, 1835420 };

void solve() {
    std::cin >> k;
    // for (int k = 1; k <= 15; k++) {
    //     res = i = 0;
    //     while (res <= k) {
    //         res += (1.0 / ++i);
    //     }
    //     std::cout << i << '\n';
    // }
    // std::cout << table[k] << '\n';
    std::cout << (int)(exp(k - gamma) + 0.5) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}