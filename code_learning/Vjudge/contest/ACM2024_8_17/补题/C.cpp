#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    vector<map<int, int>> v(26);
    vector<int> in(26), vis(26);
    for (auto& x : s) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        auto x = s[i], y = s[i + 1];
        bool flag = true;
        for (int j = 0; j < (int)min(x.size(), y.size()); j++) {
            if (x[j] == y[j]) continue;
            v[x[j] - 'a'][y[j] - 'a']++;
            if (v[x[j] - 'a'][y[j] - 'a'] == 1) in[y[j] - 'a']++;
            flag = false;
            break;
        }
        if (flag && x.size() > y.size()) {
            cout << "Impossible" << '\n';
            return;
        }
    }
    string ans = "";
    auto topsort = [&]() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (!in[i]) q.push(i);
        }
        while (q.size()) {
            auto x = q.front(); q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            ans += (char)(x + 'a');
            for (auto [to, c] : v[x]) {
                if (--in[to] == 0) q.push(to);
            }
        }
    };
    topsort();
    cout << (ans.size() != 26 ? "Impossible" : ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}