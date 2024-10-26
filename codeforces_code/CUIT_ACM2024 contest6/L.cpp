#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;

void solve() {
    int n; cin >> n;
    int x1, y1, x2, y2;
    vector<pair<int, int>> point;
    int maxX = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        point.push_back({ x1, x2 });
        maxX = max(maxX, x2);
    }
    vector<int> pre(maxX + 1, 0), a(maxX + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[point[i].first]++, pre[point[i].second]--;
    }
    ll ans = 0;
    for (int i = 1; i <= maxX; i++) {
        a[i] = a[i - 1] + pre[i];
        ans += (a[i] > 0 ? 1 : 0);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}