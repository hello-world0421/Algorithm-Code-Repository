/*
博弈论（ sg定理 ） + 打表找规律
时间复杂度 O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ans = 0, temp = -1;
    for (int i = 0; i < 3; i++) {
        cin >> temp; ans ^= (temp - 1);
    }
    cout << (ans != 0 ? "Win\n" : "Lose\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}