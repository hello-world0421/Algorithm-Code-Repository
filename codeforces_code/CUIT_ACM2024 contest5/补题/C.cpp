#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg.begin(), seg.end());
    int nxt = 0, x = -1, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (true) {
        while (!pq.empty() && pq.top() < x) pq.pop();
        if (pq.empty()) {
            if (nxt >= n) break;
            x = seg[nxt].first;
        } else {
            ans++; pq.pop(); x++;
        }
        while (nxt < n && seg[nxt].first <= x) {
            pq.push(seg[nxt].second);
            nxt++;
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