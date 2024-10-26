#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 1;
int a[MAXN], b[MAXN];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ai = 0, aj = n - 1;
    int bi = 0, bj = n - 1;
    if (ai == aj) {
        cout << "Bob\n";
        return;
    }
    while (ai <= aj && bi <= bj) {
        if ((a[ai] != b[bi] && a[ai] != b[bj]) || (a[aj] != b[bi] && a[aj] != b[bj])) {
            cout << "Alice\n";
            return;
        } else if (a[ai] == b[bi]) {
            ai++, bi++;
        } else if (a[ai] == b[bj]) {
            ai++, bj--;
        } else if (a[aj] == b[bi]) {
            aj--, bi++;
        } else if (a[aj] == b[bj]) {
            aj--, bj--;
        }
    }
    cout << "Bob\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}