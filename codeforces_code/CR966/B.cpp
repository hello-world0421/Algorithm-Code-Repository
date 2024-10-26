#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    bool check[n + 1] = {false}, ok = true;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i == 1) {
            check[num] = true;
        } else {
            if ((num - 1 >= 1 && check[num - 1] == true) || (num + 1 <= n && check[num + 1] == true)) {
                check[num] = true;
            } else {
                ok = false;
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}