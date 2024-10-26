#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;
int a[MAXN];

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int flag = 0;
    sort(a + 1, a + 1 + n);
    if (n <= 3) {
        cout << 1 << endl;
        return;
    }
    int pp = a[2] - a[1];
    int num = 2;
    int ans = 0;
    for (int i = 3; i <= n; i++) {
        if ((a[i] - a[1]) % pp == 0 && (a[i] - a[1]) / pp == num) {
            num++;
        } else {
            ans = a[i];
            flag++;
            if (flag >= 2) {
                break;
            }
        }
    }
    if (flag < 2 && num == n - 1 && mp.count(ans)) {
        cout << mp[ans] << endl;
        return;
    }
    pp = a[3] - a[1];
    num = 2;
    flag = 0;
    for (int i = 4; i <= n; i++) {
        if ((a[i] - a[1]) % pp == 0 && (a[i] - a[1]) / pp == num) {
            num++;
        } else {
            flag = 1;
            break;
        }
    }
    if (!flag && num == n - 1) {
        cout << mp[a[2]] << endl;
        return;
    }
    pp = a[3] - a[2];
    num = 2;
    flag = 0;
    for (int i = 4; i <= n; i++) {
        if ((a[i] - a[2]) % pp == 0 && (a[i] - a[2]) / pp == num) {
            num++;
        } else {
            flag = 1;
            break;
        }
    }
    if (!flag && num >= n - 1) {
        cout << mp[a[1]] << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}