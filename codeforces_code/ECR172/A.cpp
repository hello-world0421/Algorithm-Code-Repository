#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::vector<int> pre(n + 1);
    std::partial_sum(a.begin(), a.end(), pre.begin() + 1);

    int ans = -1, l = 0, r = n, mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (pre[mid] <= k) {
            ans = mid; l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << k - pre[ans] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}