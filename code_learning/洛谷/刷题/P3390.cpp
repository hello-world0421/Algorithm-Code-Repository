#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAXN = 101;

constexpr int mod = 1e9 + 7;

int n;
i64 k;

struct matrix {
    i64 g[MAXN][MAXN] = { 0 };

    matrix operator*(const matrix& b)const {
        matrix c;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                c.g[i][j] = 0;
                for (int k = 1; k <= n; k++) {
                    c.g[i][j] = (c.g[i][j] + g[i][k] * b.g[k][j] % mod) % mod;
                }
            }
        return c;
    }

    matrix operator^(i64 k) {
        matrix ans, x = *this;
        for (int i = 1; i <= n; i++)
            ans.g[i][i] = 1;
        while (k > 0) {
            if (k & 1)
                ans = ans * x;
            x = x * x; k >>= 1;
        }
        return ans;
    }
} mat, ans;

void solve() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> mat.g[i][j];

    ans = mat ^ k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cout << ans.g[i][j] << " \n"[j == n];
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}