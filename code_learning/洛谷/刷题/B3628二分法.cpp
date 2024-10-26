#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;

int n;

int a[MAXN];

int l, r, ans, mid;

void solve() {
    cin >> n;
    l = 1, r = 1, ans = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) r += -a[i];
    }

    auto check = [&](int init) {
        for (int i = 0; i < n; i++) {
            init += a[i];
            if (init <= 0) return false;
        }
        return true;
    };

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid; r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}