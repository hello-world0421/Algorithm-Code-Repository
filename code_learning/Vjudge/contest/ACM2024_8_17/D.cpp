#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int v[N], w[N];
int vis[N];
void solve() {
    int n, c, d;
    char s;
    cin >> n >> c >> d;
    vector<int> a, b;
    int maa = 0, mbb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s;
        if (s == 'C' && w[i] <= c) {
            a.push_back(i);
            maa = max(maa, v[i]);
        } else if (s == 'D' && w[i] <= d) {
            b.push_back(i);
            mbb = max(mbb, v[i]);
        }
    }
    // cout << maa << " " << mbb << endl;
    int mac = 0;
    for (auto i : a) {
        for (auto j : a) {
            if (w[i] + w[j] <= c && i != j) {
                mac = max(v[i] + v[j], mac);
            }
        }
    }
    int mad = 0;
    for (auto i : b) {
        for (auto j : b) {
            if (w[i] + w[j] <= c && i != j) {
                mad = max(v[i] + v[j], mad);
            }
        }
    }
    int mcc = 0;
    if (maa == 0 || mbb == 0) {
        mcc = 0;
    } else {
        mcc = mbb + maa;
    }
    int ma = max(mac, max(mad, mcc));
    cout << ma << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}