#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (d >= n) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n, -1);
    for (int i = 1, j = 0; i <= n; i++) {
        while (ans[j] != -1) j++;
        if (mp[i] > 0) {
            for (int k = j; k < n && mp[i] > 0; k += d) {
                if (k < n && ans[k] == -1) ans[k] = i, mp[i]--;
                else if (ans[k] != -1) k++;
            }
        }
    }
    for (int i = 1, j = 0; i <= n;) {
        while (mp[i] == 0) i++;
        while (ans[j] != -1) j++;
        ans[j++] = i; mp[i]--;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}