#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 10;
std::vector<std::vector<i64>> ans(1, std::vector<i64>(2));
std::vector<std::vector<i64>> a(2, std::vector<i64>(2));

std::vector<std::vector<i64>> matrixMultply(const std::vector<std::vector<i64>>& a, const std::vector<std::vector<i64>>& b) {
    i64 n = a.size(), m = b[0].size(), s = b.size();
    assert(a[0].size() == b.size());
    std::vector<std::vector<i64>> res(n, std::vector<i64>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < s; ++k) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return res;
}

std::vector<std::vector<i64>> matrixPow(std::vector<std::vector<i64>> a, i64 k) {
    int n = a.size();
    std::vector<std::vector<i64>> res(n, std::vector<i64>(n));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (k) {
        if (k & 1) res = matrixMultply(res, a);
        a = matrixMultply(a, a);
        k >>= 1;
    }
    return res;
}

void solve() {
    i64 n; std::cin >> n;
    if (n == 0) {
        std::cout << n << '\n';
        return;
    }
    a[0][0] = 0; a[1][1] = a[0][1] = a[1][0] = 1;
    ans[0][0] = 0; ans[0][1] = 1;
    std::cout << matrixMultply(ans, matrixPow(a, n - 1))[0][1] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    i64 tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}