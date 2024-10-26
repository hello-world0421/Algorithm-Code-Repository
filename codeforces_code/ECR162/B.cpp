#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1), dis(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        dis[abs(temp)] += a[i];
    }
    int i = 0, j = 1;
    bool ok = true;
    while (i < n) {
        int temp = k;
        if (dis[i + 1] > temp) {
            ok = false;
            break;
        }
        while (dis[j] == 0) {
            j++;
        }
        while (j <= n && dis[j] >= 0 && temp > 0) {
            if (temp >= dis[j]) {
                temp -= dis[j];
                dis[j] = 0;
                j++;
            } else {
                dis[j] -= temp;
                break;
            }
        }
        if (dis[n] == 0) {
            break;
        }
        i++;
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