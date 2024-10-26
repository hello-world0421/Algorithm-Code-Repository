#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, INT_MIN);
    int ans = a[0];
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max({ dp[i], a[i], a[i] + dp[i - 1] });
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}