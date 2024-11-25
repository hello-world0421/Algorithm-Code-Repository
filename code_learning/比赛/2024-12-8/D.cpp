#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 998244353;
constexpr int MAXN = 302;

int n;
std::vector<int> v(MAXN);
int p, q, c, t;
std::vector<std::pair<int, std::vector<int>>> w, b;

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    std::cin >> p;
    while (p--) {
        int bouns, num; std::cin >> bouns >> num;
        std::vector<int> vp(num);
        for (int i = 0; i < num; i++) {
            std::cin >> vp[i];
        }
        w.push_back(std::make_pair(bouns, vp));
    }
    std::cin >> q;
    while (q--) {
        int fath, num; std::cin >> fath >> num;
        std::vector<int> vc(num);
        for (int i = 0; i < num; i++) {
            std::cin >> vc[i];
        }
        b.push_back(std::make_pair(fath, vc));
    }

}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}