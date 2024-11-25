#include <bits/stdc++.h>

void solve() {
    int n, x; std::cin >> n >> x;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (i != x && ((i + x) & 1) == 0)
            ans++;
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}