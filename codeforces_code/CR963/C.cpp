#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    int mod = k * 2;
    cin >> n >> k;
    vector<int> a(n);
    int max_num = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i], max_num = max(max_num, a[i]);

    for (int i = max_num; i <= max_num + k - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
            if (((i - a[j]) / k) % 2 == 0) {
                flag++;
            }
        if (flag == n - 1) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}