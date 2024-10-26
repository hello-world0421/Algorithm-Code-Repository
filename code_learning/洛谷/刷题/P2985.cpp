#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, d; cin >> n >> d;
    ll l = 0, r = 0, mid, ans = -1;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        r += h[i];
    }
    auto check = [&](ll aim) {
        ll now = 0, cnt = 0, i = 0;
        while (i < n) {
            if (now >= aim) { cnt++; now >>= 1; continue; }
            while (i < n && now < aim) {
                now += h[i++];
            }
            if (now >= aim) { cnt++; now >>= 1; }
        }
        while (now >= aim) { cnt++; now >>= 1; }
        return cnt >= d;
    };

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid; l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    ll cnt = 1, now = 0;
    for (int i = 0; i < n; i++) {
        while (now >= ans) { cnt++; now >>= 1; }
        now += h[i];
        if (cnt >= d) { cout << d << '\n'; } else { cout << cnt << '\n'; }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}