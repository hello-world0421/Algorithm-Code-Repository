/*
树状数组 : 经典维护区间种类数
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;
int n;

// last[i]: 第 i 种书最后出现的下标
// f[i]: 有几个下标 x 满足 g(x) = i，后缀和就是答案
int last[MAXN], f[MAXN];
int tree[MAXN];

int lb(int x) { return x & -x; }

void add(int pos, int val) {
    while (pos <= n) {
        tree[pos] += val;
        pos += lb(pos);
    }
}

int query(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos -= lb(pos);
    }
    return ret;
}

void solve() {
    cin >> n;
    memset(last, 0, sizeof(int) * (n + 1));
    memset(f, 0, sizeof(int) * (n + 1));
    memset(tree, 0, sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (last[x] == 0) {
            // 第一次看这本书，肯定要去书柜拿
            f[n]++;
        } else {
            // 桌子大小不超过 [last[x] + 1, i - 1] 里的元素种类数时，才需要去书柜拿
            f[query(i - 1) - query(last[x])]++;
            // 树状数组维护每种元素最后出现的下标
            add(last[x], -1);
        }
        // 树状数组维护每种元素最后出现的下标
        add(i, 1);
        last[x] = i;
    }

    // 后缀和一次性求出答案
    for (int i = n - 1; i > 0; i--) f[i] += f[i + 1];
    for (int i = 1; i <= n; i++) cout << f[i] << "\n "[i < n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}