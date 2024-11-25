#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int, vector<int>)> f = [&](int pos, vector<int> path) {
            if (pos == nums.size()) {
                ans.emplace(path);
            } else {
                f(pos + 1, path);
                path.push_back(nums[pos]);
                f(pos + 1, path);
            }
        };

        f(0, vector<int>());
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4, 4, 4, 1, 4 };

    vector<vector<int>> ans = solution.subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}