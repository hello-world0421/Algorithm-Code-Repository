#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N = 1e6 + 10;
int a[N], b[N];
void solve() {

    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= n; i++) {
        mp[b[i]] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans++;
        if (a[i] >= a[i - 1] && mp[a[i]] == mp[a[i - 1]] + 1) {
            ans--;
        }
    }

    if (ans <= k) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

signed main() {
    // cin.tie(nullptr)->sync_with_stdio(false);

    int tt;
    cin >> tt;
    //cout << tt;
    while (tt--) {
        solve();
    }

}