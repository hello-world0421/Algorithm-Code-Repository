#include <bits/stdc++.h>

constexpr int MAXN = 1e6 + 2;
int n;
bool visit[2001];
int a[MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n; std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i <= 2000; i++) {
        visit[i] = false;
    }
    std::vector<std::pair<int, int>> b;
    for (int i = n; i >= 1; i--) {
        if (!visit[a[i]]) {
            b.push_back({ a[i], i });
            visit[a[i]] = true;
        }
    }
    int ans = -1;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (gcd(b[i].first, b[j].first) == 1) {
                ans = std::max(ans, b[i].second + b[j].second);
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}