#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> mp;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        mp[i - temp].push_back(temp);
    }

    ll ans = 0;
    for (auto& p : mp) {
        vector<int>& a = p.second;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i + 1 < a.size(); i += 2) {
            int res = a[i] + a[i + 1];
            if (res <= 0) break;
            ans += res;
        }
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