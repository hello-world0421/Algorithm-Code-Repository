#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0, a; i < n; i++)
        cin >> a;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    int cnt[n] = { 0 };
    int siz = 0;
    for (int i = 0; i < n; siz++, i++) {
        cnt[siz]++;
        while (i + 1 < n && b[i + 1] == b[i]) {
            cnt[siz]++; i++;
        }
    }
    int ans = 0;
    for (int i = 0; i < siz; i++) {
        if (cnt[i] == 1) {
            cout << -1 << '\n'; return;
        }
        ans += (cnt[i] + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}