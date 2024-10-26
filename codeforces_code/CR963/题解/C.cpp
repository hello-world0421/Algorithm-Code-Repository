/*
前缀和 + 双指针
时间复杂度 O(n + 2k)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, d[2 * N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        int mx = -1, mod = 2 * k;
        fill(d, d + 2 * k, 0);

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            assert(x >= 1);
            d[x % mod]++;
            mx = max(mx, x);
        }

        int cnt = 0;
        int ans = INT_MAX;
        // 前缀和
        for (int i = 0; i <= k - 2; i++)
            cnt += d[i];

        for (int l = 0, r = k - 1; l < mod; l++, r++) {
            if (r >= 2 * k)
                r %= mod;
            if ((cnt += d[r]) == n) {
                int wait = (r - mx) % mod;
                if (wait < 0)
                    wait += mod;
                ans = min(ans, mx + wait);
            }
            cnt -= d[l];
        }

        if (ans == INT_MAX)
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}