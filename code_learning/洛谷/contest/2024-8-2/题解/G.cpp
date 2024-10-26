/*
动态规划 (dp)
时间复杂度 O(nm)
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define vi vector<int>
#define ll long long
using namespace std;

void solve() {
    int n , m;
    cin >> n >> m;
    vi a(n + 1) , b(m + 1);
    // 维护所有技能伤害中的最大值
    int maxa = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i] , maxa = max(maxa , a[i]);
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    // dp[j] 表示 Boss 被攻击剩下 j 点生命时的最小输出
    vi dp(m + 1 , inf);
    dp[m] = 0;
    for (int j = m; j > 0; j--)
        for (int i = 1; i <= n; i++)
            if (j + a[i] <= m)
                dp[j] = min(dp[j] , dp[j + a[i]] + b[j]);
    // 因为受到致命一击后不再攻击
    // 所以当 Boss 生命小于 maxa 时的所有可能的最小值即为答案
    for (int j = 1; j <= min(m , maxa); j++)
        dp[0] = min(dp[0] , dp[j]);
    cout << dp[0] << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}