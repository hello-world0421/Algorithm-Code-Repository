#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 5e5 + 1;
int n, m, A[MAXN], B[MAXN];
ll ans;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    ll now = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        now += B[i];
        a.push_back(A[i] - B[i]);
    }
    if (2 * n - 1 <= m) ans = now;
    else ans = 0;
    sort(a.begin(), a.end(), greater<int>());

    now += a[0];
    for (int i = 1; i < n; i++) {
        now += a[i];
        if (2 * n - 1 - i <= m) ans = max(ans, now);
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