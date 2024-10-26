#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 1;
int fa[MAXN], dep[MAXN];
int c1[MAXN], c2[MAXN], len[MAXN];

void solve() {
    int n; ll w; cin >> n >> w;
    for (int i = 2; i <= n; i++) cin >> fa[i];
    for (int i = 2; i <= n; i++) dep[i] = dep[fa[i]] + 1;
    for (int i = 1; i <= n; i++) len[i] = c1[i] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}