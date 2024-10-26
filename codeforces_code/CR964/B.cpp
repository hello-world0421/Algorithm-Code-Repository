#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[2], b[2]; cin >> a[0] >> a[1] >> b[0] >> b[1];
    int ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            int res = 0;
            if (a[i] > b[j]) {
                res++;
            } else if (a[i] < b[j]) {
                res--;
            }
            if (a[i ^ 1] > b[j ^ 1]) {
                res++;
            } else if (a[i ^ 1] < b[j ^ 1]) {
                res--;
            }
            if (res > 0)
                ans++;
        }
    cout << ans << '\n';
}

int main() {
    int tt; cin >> tt;
    while (tt--)
        solve();

    return 0;
}