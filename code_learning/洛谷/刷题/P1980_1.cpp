#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, x, m = 1, ans = 0; std::cin >> n >> x;
    while (m <= n) {
        int a = n / (m * 10), b = n / m % 10, c = n % m;
        if (x) {
            if (b > x) ans += (a + 1) * m;
            else if (b == x) ans += a * m + c + 1;
            else if (b < x) ans += a * m;
        } else {
            if (b) ans += a * m;
            else ans += (a - 1) * m + c + 1;
        }
        m *= 10;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}