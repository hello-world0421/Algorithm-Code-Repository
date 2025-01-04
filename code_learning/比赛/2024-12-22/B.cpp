#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    int aim = k, cnt = 0;
    while (aim < n) aim += k;
    cnt = aim % n;
    for (int i = 0; i < n; i++) {
        a[i] = aim / n;
        if (cnt) a[i]++, cnt--;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}