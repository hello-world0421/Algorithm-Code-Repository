#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    // 找到第一个0的位置p
    int p = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p = i;
            break;
        }
    }

    // 如果没有0，说明全是1，直接返回[1,n]和[1,1]的答案
    if (p == n) {
        cout << "1 " << n << " 1 1\n";
        return;
    }

    // 计算0之前的1的数量
    int q = 0;
    while (q < p && s[q] == '1') {
        q++;
    }

    // 第二个子串的长度是n - p + 1
    int len = n - p + 1;

    // 第二个子串的开始位置可以在[1, p-1]范围内，尽量让它的前缀1的长度最小
    int start = min(p - 1, q);

    // 输出结果
    cout << "1 " << n << " " << start + 1 << " " << start + len - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
