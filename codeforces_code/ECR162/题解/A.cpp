#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a, ans = 0, temp = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            ok = true;
            ans += temp;
            temp = 0;
        } else if (a == 0 && ok) {
            temp++;
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