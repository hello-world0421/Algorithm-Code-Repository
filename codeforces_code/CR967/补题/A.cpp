#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a; cin >> n;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        freq[a]++;
    }
    cout << n - *max_element(freq.begin(), freq.end()) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}