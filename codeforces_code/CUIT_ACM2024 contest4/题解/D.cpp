/*
二分答案法 + 贪心
时间复杂度 O(log(maxV - minV) * n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> A(n), B(n);
    int t1, t2, minV = INT_MAX, maxV = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        minV = min(minV, t1);
        maxV = max(maxV, t1);
        A.push_back({ t1, t2 });
        B.push_back({ t1, t2 });
    }
    // 按其能力值降序排列
    sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first + a.second > b.first + b.second;
    });
    // 按其困难度降序排列
    sort(B.begin(), B.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    // 贪心地理解为 n 个人解决 m 个任务，每个人均有不同的能力值，每个任务均有不同的难度值，每个人只能完成一个任务
    // 则贪心的思路为能力越大，分配到的任务越难，返回能否完成任务
    auto check = [&](const ll& aim) {
        vector<int> power, diff;
        for (int i = 0; i < n; i++) {
            // 不小于 aim 的人负责完成任务，小于 aim 的人被视为任务
            if (A[i].first >= aim) power.push_back(A[i].first + A[i].second - aim);
            if (B[i].first < aim) diff.push_back(B[i].second);
        }
        if (power.size() < diff.size()) return false;
        for (int i = 0; i < diff.size(); i++) {
            if (power[i] < diff[i]) return false;
        }
        return true;
    };

    int l = minV, r = maxV;
    ll ans = -1, mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}