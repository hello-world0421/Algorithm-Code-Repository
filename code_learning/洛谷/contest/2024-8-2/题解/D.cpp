/*
树状数组
时间复杂度 O(nlogn)
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

class Fenwick {
public:
    vector<ll> tree;
    int n;

    Fenwick() {}

    Fenwick(int x) {
        init(x);
    }

    void init(int x) {
        n = x;
        tree.resize(n + 1);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int i, ll v) {
        while (i <= n) {
            tree[i] += v;
            i += lowbit(i);
        }
    }

    ll sum(int x) {
        ll ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

    ll rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a.begin() + 1, a.end(), [](pair<ll, ll> A, pair<ll, ll> B) {
        if (A.first == B.first) return A.second < B.second;
        return A.first < B.first;
        });

    Fenwick tree1(n), tree2(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (tree1.sum(n) - tree1.sum(a[i].second)) * a[i].first + (tree2.sum(n) - tree2.sum(a[i].second));
        tree1.add(a[i].second, 1), tree2.add(a[i].second, a[i].first);
    }
    cout << ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}