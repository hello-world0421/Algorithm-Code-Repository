/*
前缀和 + 预处理
时间复杂度 O(1)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 1;
int tabel[MAXN], pre[MAXN];
int l, r;

void solve() {
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] + tabel[l] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    tabel[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        tabel[i] = tabel[i / 3] + 1;
        pre[i] = tabel[i] + pre[i - 1];
    }

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}