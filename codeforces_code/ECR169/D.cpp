#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 1;
vector<pair<int, int>> adj[MAXN];

void solve() {
    int n, q; cin >> n >> q;
    string s;
    map<char, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        mp[s[0]].push_back(i);
        mp[s[1]].push_back(i);
    }
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}