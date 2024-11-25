#include <bits/stdc++.h>

void solve() {
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ans++;
        } else {
            c.push_back(b[i] - a[i] + 1);
        }
    }
    std::sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        if (x >= c[i]) {
            ans++;
            x -= c[i];
        } else {
            break;
        }
    }
    std::cout << (ans > n - ans ? "YES" : "NO") << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}