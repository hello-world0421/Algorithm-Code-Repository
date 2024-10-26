/*
博弈题
时间复杂度 O(1)

必败态为 : 当只剩下两只恶魔时必然编号小的恶魔会独吞所有金币
故只要最小化的争取到编号大的恶魔的赞成票就可以满足题意
*/
#include <bits/stdc++.h>
using namespace std;

int x, n;

void solve() {
    cin >> x >> n;
    cout << x - ((n - 1) / 2) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}