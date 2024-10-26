#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;
vector<pair<int, int>> points;
pair<int, int> s, e;

void solve() {
    int n; cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    cin >> s.first >> s.second >> e.first >> e.second;
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}