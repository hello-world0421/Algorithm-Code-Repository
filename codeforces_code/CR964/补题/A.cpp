/*
思维题
时间复杂度 O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << n / 10 + n % 10 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}