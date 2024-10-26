/*
树状数组 + 容斥原理
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[20001], tree[100001];

inline int lowbit(int x) {
    return x & -x;
}

void update(int x, int k) {
    while (x <= 100000) {
        tree[x] += k;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x != 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int l_low[20001], l_up[20001], r_low[20001], r_up[20001];
int l_cnt[20001], r_cnt[20001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> n;
        // 正向跑一遍树状数组
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            l_low[i] = query(a[i]);
            l_up[i] = query(100000) - query(a[i] - 1);
            l_cnt[i] = query(a[i]) - query(a[i] - 1);
            update(a[i], 1);
        }

        for (int i = 1; i <= 100000; i++) {
            tree[i] = 0;
        }

        // 反向跑一遍树状数组
        for (int i = n; i >= 1; i--) {
            r_low[i] = query(a[i]);
            r_up[i] = query(100000) - query(a[i] - 1);
            r_cnt[i] = query(a[i]) - query(a[i] - 1);
            update(a[i], 1);
            ans += (ll)r_low[i] * (ll)l_up[i];
            ans += (ll)l_low[i] * (ll)r_up[i];
            // 容斥原理
            ans -= l_cnt[i] * r_cnt[i];
        }

        for (int i = 1; i <= 100000; i++) {
            tree[i] = 0;
        }

        cout << ans << '\n';
    }
}