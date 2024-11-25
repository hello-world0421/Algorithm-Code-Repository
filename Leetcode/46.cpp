#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        function<void(vector<int>&, int)> f = [&](vector<int>& nums, int pos) {
            if (pos == nums.size()) {
                ans.push_back(nums);
            } else {
                for (int i = pos; i < nums.size(); i++) {
                    swap(nums[pos], nums[i]);
                    f(nums, pos + 1);
                    swap(nums[pos], nums[i]);
                }
            }
        };

        f(nums, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> ans = solution.permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}