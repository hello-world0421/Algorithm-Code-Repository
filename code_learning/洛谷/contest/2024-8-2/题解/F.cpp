/*
二分答案法
时间复杂度 O(mlogn)
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define vi vector<int>
#define endl '\n'
#define ll long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> lp(m + 1), rp(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> lp[i] >> rp[i];

    // 二分答案法的 check 函数
    auto check = [&](int tim) -> bool {
        int L = 0, R = n + 1;
        for (int i = 1; i <= m; i++)
            if (rp[i] - lp[i] > tim)
                L = max(L, lp[i]), R = min(R, rp[i]);
        int len = max(R - L, 0);
        for (int i = 1; i <= m; i++)
            if (rp[i] - lp[i] > tim && rp[i] - lp[i] - len > tim)
                return false;
        return true;
        };

    // 二分的过程
    int l = 0, r = n, mid, ans;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}