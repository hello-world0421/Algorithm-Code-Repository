#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MAXN = 2e5 + 1;
int bits[MAXN];

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> bits[i];
    }
    sort(bits + 1, bits + n + 1);
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 20; j++) {
            if (i + j > n)
                break;
            int res = 0;
            for (int k = 0; k < m; k++) {
                if (((bits[i] & (1 << k)) ^ (bits[i + j] & (1 << k))) == 0) {
                    res |= (1 << k);
                }
            }
            ans = max(ans, res);
        }
    }
    cout << ans;

    return 0;
}