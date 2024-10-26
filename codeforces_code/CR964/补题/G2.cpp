/*
三分搜索 + 交互
时间复杂度 只需 7 次
*/
#include <bits/stdc++.h>

int query(int a, int b) {
    std::cout << "? " << a << " " << b << std::endl;
    int res; std::cin >> res;
    return res;
}

void solve() {
    int left = 2, right = 999, ans = -1, mid1, mid2;
    while (left <= right) {
        mid1 = left + ((right - left) / 3);
        mid2 = left + (right - mid1);
        int res = query(mid1, mid2);
        if (res == mid1 * mid2) {
            left = mid2 + 1;
        } else if (res == (mid1 + 1) * (mid2 + 1)) {
            ans = mid1;
            right = mid1 - 1;
        } else if (res == mid1 * (mid2 + 1)) {
            ans = mid2;
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    std::cout << "! " << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(0);

    int t; std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}