#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int i = 0, j = 2, ans = 2;
    while (j < n) {
        if (a[i] + a[i + 1] > a[j]) {
            ans = std::max(ans, j - i + 1);
            j++;
        } else {
            while (j < n && a[i] + a[i + 1] <= a[j]) {
                i++;
                if (j < i + 2) j++;
            }
        }
    }
    std::cout << n - ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}