/*
贪心
时间复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 1;
int a[MAXN], n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        cout << min(a[0], a[1]) << '\n';
    } else {
        int ans = INT_MIN;
        for (int i = 1; i < n - 1; i++) {
            int b[3] = {a[i - 1], a[i], a[i + 1]};
            sort(b, b + 3);
            ans = max(ans, b[1]);
        }
        cout << ans << '\n';
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}