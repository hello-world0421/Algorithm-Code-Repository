#include <bits/stdc++.h>

void solve() {
    int a[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + 3);
    if (a[0] + a[1] == a[2])
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();
}