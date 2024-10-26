#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 5e3 + 1;
int n;
ll ans;
pair<ll, ll> point[MAXN];
ll dp[MAXN][MAXN];

pair<ll, ll> vec(pair<ll, ll> point1, pair<ll, ll> point2) {
    return make_pair(point2.first - point1.second, point2.second - point1.second);
}

ll cross(pair<ll, ll> vec1, pair<ll, ll> vec2) {
    return vec1.first * vec2.second - vec2.first * vec1.second;
}

ll dis2(int i, int j) {
    return (point[i].first - point[j].first) * (point[i].first - point[j].first) + (point[i].second - point[j].second) * (point[i].second - point[j].second);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    // 区间 dp
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        dp[i][j] = dis2(i, j);
    }
    for (int len = 3; len <= n; len++) for (int i = 0; i < n; i++) {
        int j = (i + len - 1) % n;
        dp[i][j] = max({ dp[(i + 1) % n][j], dp[i][(j - 1 + n) % n], dis2(i, j) });
    }

    ans = 9e18;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n, pre = (i - 1 + n) % n;
        for (int j = 0; j < n; j++) if (i != j) {
            ll c1 = cross(vec(point[j], point[i]), vec(point[nxt], point[i]));
            ll c2 = cross(vec(point[j], point[i]), vec(point[pre], point[i]));
            if (c1 == 0 || c2 == 0) continue;
            ans = min(ans, dp[i][j] + dp[j][i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}