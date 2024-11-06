#include <bits/stdc++.h>

int a[3];

void solve() {
    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a, a + 3);
    std::cout << (a[0] + a[1] == a[2] ? "YES\n" : "NO\n");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}