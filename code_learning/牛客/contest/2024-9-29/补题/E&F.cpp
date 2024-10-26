#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 2e6 + 1000;

int n, m, root[N], id = 1;

struct node {
    int l, r, val;
} seg[N];

void build(int version, int l, int r) {
    if (l == r) {
        seg[version].val = 0;
        return;
    }
    int mid = l + ((r - l) >> 1);
    seg[version].l = ++id, seg[version].r = ++id;
    build(seg[version].l, l, mid);
    build(seg[version].r, mid + 1, r);

    seg[version].val = seg[seg[version].l].val + seg[seg[version].r].val;
}

void update(int l, int r, int last, int now, int pos, int val) {
    if (l == r) {
        seg[now].val = seg[last].val + val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    seg[now].l = seg[last].l, seg[now].r = seg[last].r;
    if (pos <= mid) {
        seg[now].l = ++id;
        update(l, mid, seg[last].l, seg[now].l, pos, val);
    } else {
        seg[now].r = ++id;
        update(mid + 1, r, seg[last].r, seg[now].r, pos, val);
    }

    seg[now].val = seg[seg[now].l].val + seg[seg[now].r].val;
}

int query(int l, int r, int last, int now, int k) {
    if (l == r) return l;

    int mid = l + ((r - l) >> 1), d = seg[seg[now].l].val - seg[seg[last].l].val;
    if (d < k) {
        return query(mid + 1, r, seg[last].r, seg[now].r, k - d);
    } else {
        return query(l, mid, seg[last].l, seg[now].l, k);
    }
}

void solve() {
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b.emplace_back(a[i]);
    }
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    int len = b.size();
    root[0] = 1;
    build(root[0], 1, len);

    auto get = [&](int x) {
        return std::lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    for (int i = 1; i <= n; i++) {
        int p = get(a[i]);
        root[i] = ++id;
        update(1, len, root[i - 1], root[i], p, 1);
    }

    while (m--) {
        int l, r, k;
        std::cin >> l >> r;
        k = (r - l + 1 + 1) / 2;
        std::cout << b[query(1, len, root[l - 1], root[r], k) - 1] << "\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}