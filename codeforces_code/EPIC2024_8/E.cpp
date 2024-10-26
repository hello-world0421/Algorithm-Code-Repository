#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> nums(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first >> nums[i].second;
        mp[nums[i].second] += nums[i].first;
    }
    pair<int, int> pre = { nums[0].first, nums[0].second };
    int sum = 0;
    mp[pre.second] -= pre.first;
    cout << pre.first << " ";
    for (int i = 1; i < n; i++) {
        mp[nums[i].second] -= nums[i].first;
        if (nums[i].second != pre.second && nums[i].first >= pre.first) {
            sum = max(sum, nums[i].first);
            if (nums[i].first > pre.first) {
                pre.first = nums[i].first;
                pre.second = nums[i].second;
            } else {
                if (mp[pre.second] < mp[nums[i].second]) {
                    pre.first = nums[i].first;
                    pre.second = nums[i].second;
                }
            }
            cout << pre.first << " \n"[i == n - 1];
        } else if (nums[i].second == pre.second) {
            
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}