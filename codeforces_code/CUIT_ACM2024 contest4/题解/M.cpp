/*
计算几何 + 旋转卡壳
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 1;

int n, k;
pair<ll, ll> point[MAXN];

// 求向量积
ll cross(int a, int b) {
    return point[a].first * point[b].second - point[b].first * point[a].second;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;

    // 多边形的面积 == 各相邻点的向量积之和 / 2
    ll ans = 0, sm = 0;
    for (int i = 1; i <= k; i++) sm += cross(i - 1, i);

    // 枚举点 b
    for (int b = 0, a = k; b < n; b++) {
        int c = (b + k) % n;
        // 类似旋转卡壳，随着 bc 的逆时针旋转，最优的 a 的位置也会逆时针旋转
        while (a != b) {
            ll now = cross(c, a) + cross(a, b);
            ll nxt = cross(c, (a + 1) % n) + cross((a + 1) % n, b);
            if (nxt > now) a = (a + 1) % n;
            else break;
        }
        ans = max(ans, sm + cross(c, a) + cross(a, b));
        sm += cross(c, (c + 1) % n) - cross(b, (b + 1) % n);
        // a 要始终处于 c 到 b 之间
        if (a == c) a = (a + 1) % n;
    }
    cout << fixed << setprecision(12) << ans / 2.0 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}