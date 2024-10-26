/*
位图
时间复杂度 预处理 + O(1)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e9 + 1;
constexpr int MAXM = MAXN / 64 + 1;
ll bitSet[MAXM];

void solve() {
    int n; cin >> n;
    cout << (bitSet[n / 64] & (1ll << (n % 64)) ? 1 : 0) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    ll a = 1, b = 1;
    while (a <= MAXN) {
        bitSet[a / 64] |= (1ll << (a % 64));
        a += b++;
    }
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}