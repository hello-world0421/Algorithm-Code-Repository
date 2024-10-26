/*
模拟 + 排序 + 字符串处理
时间复杂度 O(|s| + nlogn) , 其中 n 为字符串中数字的数量
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    int num = 0;
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            res.push_back(num);
            num = 0;
        } else {
            num *= 10;
            num += s[i] - '0';
        }
    }
    res.push_back(num);

    sort(res.begin(), res.end(), [](int a, int b) {
        return a > b;
        });

    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? '+' : '\n');
        ans += res[i];
    }
    cout << ans << '\n';
}