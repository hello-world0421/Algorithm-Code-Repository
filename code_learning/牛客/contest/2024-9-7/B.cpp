#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
    }
    cout << (n == 1 ? -1 : (n + 1) / 2) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}