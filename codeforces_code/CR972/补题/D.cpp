#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;
int a[N], b[N];
int pa[N], pb[N], sa[N], sb[N];
int n;

ll dp[N][3];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll solve_one(ll ga, ll gb) {
    if (ga <= 0 || gb <= 0) return 0;
    if (b[1] % gb) return 0;

    for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++)
        dp[i][j] = 0;

    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k <= j; k++) {
                bool flag = 1;

                if (j == 1) swap(a[i], b[i]);

                if (a[i] % ga) flag = 0;
                if (b[i] % gb) flag = 0;

                if (j == 1) swap(a[i], b[i]);

                if (flag) dp[i][j] += dp[i - 1][k];
            }

    return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        sa[n + 1] = sb[n + 1] = 0;

        for (int i = 1; i <= n; i++) {
            pa[i] = gcd(pa[i - 1], a[i]);
            pb[i] = gcd(pb[i - 1], b[i]);

            sa[n - i + 1] = gcd(sa[n - i + 2], a[n - i + 1]);
            sb[n - i + 1] = gcd(sb[n - i + 2], b[n - i + 1]);
        }

        if (n <= 300) {
            int max_gcd = 0, ways = 0;

            for (int i = 1; i <= n; i++) {
                int ga = 0, gb = 0;

                for (int j = i; j <= n; j++) {
                    ga = gcd(ga, a[j]);
                    gb = gcd(gb, b[j]);

                    int ca = gcd(pa[i - 1], gcd(sa[j + 1], gb));
                    int cb = gcd(pb[i - 1], gcd(sb[j + 1], ga));

                    if (ca + cb > max_gcd) {
                        max_gcd = ca + cb;
                        ways = 1;
                    } else if (ca + cb == max_gcd) ways++;
                }
            }

            cout << max_gcd << ' ' << ways << '\n';

            continue;
        }

        int max_gcd = pa[n] + pb[n];

        for (int i = 2; i <= n; i++) {
            if (pa[i] == pa[i - 1] && pb[i] == pb[i - 1])
                continue;

            int ga = 0, gb = 0;

            for (int j = i; j <= n; j++) {
                ga = gcd(ga, a[j]);
                gb = gcd(gb, b[j]);

                int ca = gcd(pa[i - 1], gcd(sa[j + 1], gb));
                int cb = gcd(pb[i - 1], gcd(sb[j + 1], ga));

                max_gcd = max(max_gcd, ca + cb);
            }
        }

        ll ans = 0;
        for (int ga = 1; ga * ga <= a[1]; ga++) {
            if (a[1] % ga) continue;

            ans += solve_one(ga, max_gcd - ga);
            if (ga * ga == a[1]) continue;
            ans += solve_one(a[1] / ga, max_gcd - a[1] / ga);
        }

        if (pa[n] + pb[n] == max_gcd) ans -= n;
        for (int i = 1; i <= n; i++)
            if (gcd(pa[i], sb[i + 1]) + gcd(pb[i], sa[i + 1]) == max_gcd) ans++;

        cout << max_gcd << ' ' << ans << '\n';
    }
}