#include <bits/stdc++.h>
using namespace std;

const string weeks[] = { "Monday", "Tuesday", "Wednesday", "Thursday" , "Friday" };

void solve() {
    string week;
    int y1, m1, d1, y2, m2, d2; cin >> y1 >> m1 >> d1 >> week >> y2 >> m2 >> d2;
    int idx = -1;
    for (int i = 0; i < 5; i++) {
        if (weeks[i] == week) {
            idx = i;
            break;
        }
    }
    cout << weeks[(((idx + d2 - d1) % 5 + 5) % 5)] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}