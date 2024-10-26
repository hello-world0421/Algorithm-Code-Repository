#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    unordered_map<int, int> mp;
    for (auto& i : b) cin >> i;
    for (auto& i : b) cin >> i, mp[i]++;

    int ans = 0;
    for (auto [x, cnt] : mp) {
        if (cnt == 1) { cout << -1 << '\n'; return; }
        ans += (cnt + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}