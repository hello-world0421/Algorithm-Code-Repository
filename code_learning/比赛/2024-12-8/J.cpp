#include <bits/stdc++.h>
using i64 = long long;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }
    int minGcd = b[1];
    std::vector<int> res;
    for (int i = 2; i <= m; i++) {
        if (minGcd == 1) {
            res.push_back(minGcd);
            minGcd = b[i]; continue;
        }
        if (minGcd <)
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}