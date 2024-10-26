#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 1;
pair<ll, ll> a[MAXN];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    ll ans = 0, cnt = 0;
    int i = 0, j = n - 1;
    while (i <= j && a[j].first > a[i].first) {
        if (a[j].second <= a[i].second) {
            ans += (a[j].first - a[i].first) * a[j].second;
            a[i].second -= a[j].second; j--;
        } else {
            ans += (a[j].first - a[i].first) * a[i].second;
            a[j].second -= a[i].second; i++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}