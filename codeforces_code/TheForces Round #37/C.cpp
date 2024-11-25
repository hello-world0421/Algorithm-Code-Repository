#include <bits/stdc++.h>
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n; std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 1, flag = 0, temp = 0;
    for (i64 i = 0; i < n; i++) {
        if (gcd(temp, a[i]) > ans) {
            temp = gcd(temp, a[i]);
        } else {
            flag++;
        }
    }
    

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}