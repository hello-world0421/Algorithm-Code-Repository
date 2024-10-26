#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 1e5 + 1;

int n;

struct item {
    i64 w, c;

    item() { w = c = 0; }

    bool friend operator < (const item& a, const item& b) {
        return a.c * b.w < b.c * a.w;
    }
} items[MAXN];

i64 v[MAXN];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> items[i].w >> v[i] >> items[i].c;
    }
    std::sort(items + 1, items + n + 1);
    i64 ans = 0, maxW = 0;
    for (int i = 1; i <= n; i++) {
        ans += v[i] - maxW * items[i].c;
        maxW += items[i].w;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}