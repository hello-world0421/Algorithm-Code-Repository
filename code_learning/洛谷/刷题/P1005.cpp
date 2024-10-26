#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 81;
int matrix[MAXN][MAXN];
ll pow2[MAXN];
int l[MAXN], r[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    ll ans = 0;
    fill(l + 1, l + n + 1, 1);
    fill(r + 1, r + n + 1, m);
    for (int i = 1; i <= m; i++) {
        ll res = 0;
        for (int j = 1; j <= n; j++) {
            res += (matrix[j][l[j]] < matrix[j][r[j]] ? matrix[j][l[j]++] : matrix[j][r[j]--]);
        }
        ans += res * pow2[i];
    }
    cout << ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    solve();

    return 0;
}