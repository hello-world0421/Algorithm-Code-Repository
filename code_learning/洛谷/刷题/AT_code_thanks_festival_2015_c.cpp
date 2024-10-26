#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 51;

int n, tmph;

int h[MAXN];

int l, r, ans, mid;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cin >> tmph;
    l = 1, r = n, ans = n + 1;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (h[mid] >= tmph) {
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