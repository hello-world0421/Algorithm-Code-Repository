/*
二分搜索 + 交互
时间复杂度 只需 10 次
*/
#include <bits/stdc++.h>

int query(int a, int b) {
    std::cout << "? " << a << " " << b << std::endl;
    int res; std::cin >> res;
    return res;
}

void solve() {
    int left = 2, right = 999, ans = -1, mid;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (query(1, mid) == mid + 1) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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