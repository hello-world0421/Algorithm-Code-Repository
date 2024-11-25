#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> generatePermutation(string s) {
        set<string> ans;

        // 使用 std::function 来定义递归的 lambda
        std::function<void(string, int, string)> dfs = [&](string s, int pos, string path) {
            if (pos == s.length()) {
                ans.emplace(path);
            } else {
                dfs(s, pos + 1, path);  // 递归调用
                path += s[pos];
                dfs(s, pos + 1, path);  // 递归调用
            }
        };

        dfs(s, 0, "");  // 开始递归
        return vector<string>(ans.begin(), ans.end());
    }
};

int main() {
    Solution solution;
    string input = "dbcq";

    // 获取所有的排列组合
    vector<string> result = solution.generatePermutation(input);

    // 输出所有生成的排列
    cout << "Generated permutations: \n";
    for (const string& perm : result) {
        cout << perm << "\n";
    }

    return 0;
}