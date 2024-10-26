#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5 + 1;

int n, k;
ll f[MAXN], tree[MAXN];
map<ll, ll> last;

ll lb(ll x) { return x & -x; }

void add(ll pos, ll val) {
    while (pos <= n) {
        tree[pos] += val;
        pos += lb(pos);
    }
}

ll query(ll pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos -= lb(pos);
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    memset(f, 0, sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (last[x] == 0) {
            f[n]++;
        } else {
            f[query(i - 1) - query(last[x])]++;
            add(last[x], -1);
        }
        add(i, 1);
        last[x] = i;
    }

    for (int i = n - 1; i > 0; i--) f[i] += f[i + 1];
    for (int i = 1; i <= n; i++) {
        cerr << f[i] << ' ';
    }
    for (int i = 1; i <= n; i++) {
        if (n - f[i] >= k) {
            cout << i << '\n';
            return;
        }
    }
    cout << "cbddl\n";
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}