#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int MAXN = 5e5 + 20;
pair<ll, ll> a[MAXN];
bitset<MAXN> mp;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second - a.first > b.second - b.first;
}

void solve() {
    int n, m; cin >> n >> m;
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].first;
        mp.set(i);
    }
    if (n == 1) {
        cout << a[0].second << '\n';
        return;
    }
    ll size = n;
    m -= n;
    sort(a, a + n, cmp);
    int i = 0;
    while (a[i].second > a[i].first && m > 0 && size > 0) {
        if (size > 2) {
            ans += (a[i].second - a[i].first);
            m--; size--; mp.reset(i);
        } else if (size == 2) {
            if (a[i + 1].second + a[i].second > a[i + 1].first + a[i].first) {
                ans += (a[i + 1].second - a[i + 1].first + a[i].second - a[i].first);
                m--; size -= 2; mp.reset(i + 1); mp.reset(i); i++;
            }
        }
        i++;
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