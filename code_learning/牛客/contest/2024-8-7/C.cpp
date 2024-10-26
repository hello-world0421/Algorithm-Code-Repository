#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;

int cal(int n, int m) {
    if (n == 1) {
        return m + 1;
    } else if (n >= 2) {
        ll ans = 0;
        for (int i = 0; i <= m; i++) {
            ans = (ans + cal(n - 1, m - i)) % MOD;
        }
        return ans % MOD;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    ll sum_a = 0, a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum_a += a;
    }
    a = m - sum_a;
    ll ans = 0;

    // cout << cal(n, a);
    
    return 0;
}