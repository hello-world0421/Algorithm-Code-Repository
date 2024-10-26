#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;

int n;

int a[MAXN], pre[MAXN], ans;

void solve() {
    cin >> n;
    ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        ans = min(pre[i + 1], ans);
    }
    cout << (ans >= 0 ? 1 : 1 - ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}