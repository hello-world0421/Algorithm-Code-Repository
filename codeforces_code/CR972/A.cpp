#include <bits/stdc++.h>
using namespace std;

const char chs[] = { 'a', 'o', 'e', 'i', 'u' };

void solve() {
    int n; cin >> n;
    for (int i = 0, times, t = n % 5; i < 5; i++) {
        times = (n / 5) + (t-- > 0 ? 1 : 0);
        for (int j = 0; j < times; j++)
            cout << chs[i];
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}