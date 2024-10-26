#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 1;
int n;
ll ans;

void solve() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    // 按商品的价格从小到大排序
    sort(a.begin(), a.end());

    // 维护两个指针，i 指向最便宜的商店，j 指向最贵的商店
    int i = 0, j = n - 1;
    ans = 0;
    while (i < j) {
        // 交易次数为两个商店交易次数的最小值
        int mn = min(a[i].second, a[j].second);
        // 计算利润
        ans += 1ll * (a[j].first - a[i].first) * mn;
        // 调整指针的位置
        a[i].second -= mn; a[j].second -= mn;
        if (a[i].second == 0) i++;
        if (a[j].second == 0) j--;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}