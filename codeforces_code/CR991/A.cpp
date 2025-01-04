#include <bits/stdc++.h>

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        a[i] = s.size();
    }
    std::vector<int> pre(n + 1, 0);
    std::partial_sum(a.begin(), a.end(), pre.begin() + 1);
    int ans = -1, l = 0, r = n, mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (m >= pre[mid]) {
            ans = mid; l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) solve();

    return 0;
}