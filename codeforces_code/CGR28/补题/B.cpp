/*
构造题
时间复杂度：O(n)
*/
#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    int j = 1;
    for (int i = k - 1; i < n; i += k) {
        a[i] = j++;
    }

    for (int i = 0; i < n; i++) {
        if (!a[i]) a[i] = j++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}