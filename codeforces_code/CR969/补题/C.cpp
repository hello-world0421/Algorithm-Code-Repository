#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    /*
        单点 +a, +b <==> 单点 +-gcd(a, b)
    */
    int n, a, b; cin >> n >> a >> b;
    int d = gcd(a, b);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i]; c[i] %= d;
    }
    sort(c.begin(), c.end());
    int ans = c[n - 1] - c[0];
    for (int i = 0; i + 1 < n; i++) {
        ans = min(ans, c[i] + d - c[i + 1]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}