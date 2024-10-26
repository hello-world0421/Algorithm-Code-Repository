#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<ll, 20> op = { 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484, 7174453, 21523360, 64570081, 193710244, 581130733, 1743392200 };

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            ans = max(ans, 1);
            continue;
        }
        for (int j = 0; j < 20; j++) {
            if (a[i] + op[j] > a[i - 1]) {
                a[i] += op[j], ans = max(ans, j + 1);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}