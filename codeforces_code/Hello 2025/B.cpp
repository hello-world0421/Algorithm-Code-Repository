#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k; std::cin >> n >> k;
    std::map<i64, int> cnt;
    for (int i = 0; i < n; i++) {
        i64 x; std::cin >> x;
        cnt[x]++;
    }
    std::vector<int> a;
    for (auto& [x, y] : cnt) {
        a.push_back(y);
    }
    std::sort(a.begin(), a.end());
    int ans = a.size();
    for (int i = 0; i < a.size() - 1; i++) {
        if (k >= a[i]) {
            k -= a[i];
            ans--;
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