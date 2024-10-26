/*
素数筛 + 位运算 + 二分查找
时间复杂度 预处理 + O(1)  预处理的常数时间比较大
*/
#include <bits/stdc++.h>
using namespace std;

// 欧拉筛 ( 又称线性筛 )
bool visit[100'000'001];
vector<int> prime;
void euler(int n) {
    visit[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!visit[i])
            prime.push_back(i);
        for (int j : prime) {
            if (j * i > n) {
                break;
            }
            visit[j * i] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    euler(100'000'000);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        // 二分搜索
        int sum = 0, l1 = 0, r1 = prime.size() - 1, l2 = 0, r2 = r1;
        int ans1 = 0, ans2 = 0;
        while (l1 <= r1) {
            int mid = l1 + ((r1 - l1) >> 1);
            if (prime[mid] >= x) {
                ans1 = mid;
                r1 = mid - 1;
            } else {
                l1 = mid + 1;
            }
        }
        while (l2 <= r2) {
            int mid = l2 + ((r2 - l2) >> 1);
            if (prime[mid] <= y) {
                ans2 = mid;
                l2 = mid + 1;
            } else {
                r2 = mid - 1;
            }
        }
        sum = ans2 - ans1 + 1;
        cout << sum << ' ';
        // 两个奇数 & 之后必不为 0
        // 所以要使得结果为 0，区间中必然要包含 2
        if (x > 2 || sum == 1) {
            cout << "0\n";
        } else if (sum >= 2) {
            cout << sum - 2 << '\n';
        }
    }

    return 0;
}