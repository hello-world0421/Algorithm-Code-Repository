#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e5 + 2;
constexpr int mod = 1e9 + 7;

i64 prec[MAXN];
void init() {
    prec[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        prec[i] = prec[i - 1] * i % mod;
    }
}

void solve() {
    int n; std::cin >> n;
    std::cout << prec[n >> 1] * prec[(n >> 1) + 1] % mod << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    init();
    solve();

    return 0;
}