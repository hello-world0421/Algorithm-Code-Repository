#include <bits/stdc++.h>

int lowbit(int a) {
    return a & -a;
}

void solve() {
    int n, k; std::cin >> n >> k;
    std::cout << (lowbit(n) <= k ? "Alice\n" : "Bob\n");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}