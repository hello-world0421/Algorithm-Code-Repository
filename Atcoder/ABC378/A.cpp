#include <bits/stdc++.h>

void solve() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + 4);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] == a[i + 1]) {
            ans++; i++;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt = 1;
    while (tt--) {
        solve();
    }
}