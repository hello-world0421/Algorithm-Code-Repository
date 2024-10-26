#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;

int n, q;

pair<int, int> a[MAXN];

int l, r, ans, mid, aim;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    cin >> q;
    while (q--) {
        cin >> aim;
        l = 1, r = n, ans = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid].first == aim) {
                ans = a[mid].second;
                break;
            } else if (a[mid].first > aim) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}