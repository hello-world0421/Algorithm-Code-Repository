/*
动态规划 + 二分答案法
时间复杂度 O(nlog(max(a)))
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, k, a[N];
int dp[N], b[N];

bool check(int med) {
    for (int i = 0; i < n; i++)
        b[i] = (a[i] >= med ? 1 : -1);

    // 动态规划
    if (n <= k) {
        dp[0] = b[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + b[i];
        }
        return dp[n - 1] > 0;
    } else {
        dp[0] = b[0];
        for (int i = 1; i < k; i++) {
            dp[i] = dp[i - 1] + b[i];
        }
        for (int i = k; i < n; i++) {
            dp[i] = max(dp[i - k], (i % k ? dp[i - 1] + b[i] : b[i]));
        }
    }
    return dp[n - 1] > 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int max_n = -1;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_n = max(max_n, a[i]);
        }

        // 二分答案法
        int left = 1, right = max_n, mid, ans = -1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (check(mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}