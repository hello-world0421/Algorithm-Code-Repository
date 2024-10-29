#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0, num; i < n * (n - 1) / 2; i++) {
        std::cin >> num;
        mp[num]++;
    }
    n--;
    for (auto [num, cnt] : mp) {
        while (cnt != 0) {
            cnt -= n--;
            std::cout << num << ' ';
        }
        if (n == 0) {
            std::cout << num << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
}