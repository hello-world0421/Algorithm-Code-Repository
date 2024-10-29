#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    auto sqrt = [&](i64 a) {
        i64 l = 0, r = a, ans = -1;
        while (r >= l) {
            i64 mid = l + ((r - l) >> 1);
            if (1ll * mid * mid <= a) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    };
    std::cout << sqrt(88) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}