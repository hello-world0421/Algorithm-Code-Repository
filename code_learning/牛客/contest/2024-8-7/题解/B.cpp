/*
位运算
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pow2(32);
    pow2[0] = 1;
    int cnt = 1;
    for (int i = 1; i <= 30; i++) {
        cnt <<= 1;
        pow2[i] = pow2[i - 1] + cnt;
    }

    int n, m; cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    int ans = INT_MAX;
    // 求同或的最大值 <==> 求异或的最小值
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, s[i] ^ s[i + 1]);
    }
    cout << pow2[m - 1] - ans;
}