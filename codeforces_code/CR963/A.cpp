#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt;
    for (int i = 0; i < 4; i++)
        cnt.push_back(n);
    string s;
    cin >> s;
    for (auto ch : s)
        if (ch >= 'A' && ch <= 'D' && cnt[ch - 'A'] > 0)
            cnt[ch - 'A']--;
    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans += (n - cnt[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}