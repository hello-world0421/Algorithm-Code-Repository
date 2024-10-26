/*
因为数组 p 为一个排列，所以 1 ~ n 内的数字当且仅当只会出现一次
对应到图中即意味着每个点都仅有一个入度和一个出度
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n + 1, 0), ans(n + 1, 0);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int sz = 0;
        while (!vis[i]) {
            vis[i] = 1;
            sz += s[i - 1] == '0';
            i = p[i];
        }
        while (vis[i] != 2) {
            ans[i] = sz;
            vis[i] = 2;
            i = p[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}