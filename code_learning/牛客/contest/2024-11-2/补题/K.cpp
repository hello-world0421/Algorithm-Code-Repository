#include <bits/stdc++.h>

constexpr int MAXN = 1e6 + 1;

// 欧拉筛 ( 又称线性筛 )
bool visit[MAXN * 3 + 7];
std::vector<int> prime;
void euler(int n) {
    visit[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!visit[i]) {
            prime.push_back(i);
        }
        for (int j : prime) {
            if (j * i > n) {
                break;
            }
            visit[j * i] = true;
            if (i % j == 0) {
                break;
            }
        }
    }
}

std::vector<int> s(MAXN, 0);
void init() {
    for (int i = 1; i < MAXN; i++) {
        s[i] = s[i - 1] + (visit[i * 3 + 7] ^ 1);
    }
}

void solve() {
    int n; std::cin >> n;
    std::cout << s[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    euler(3'000'007);
    init();
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}