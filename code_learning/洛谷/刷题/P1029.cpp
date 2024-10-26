#include <bits/stdc++.h>

int d, lcm;

int cnt, cur, x;

// 欧拉筛 ( 又称线性筛 )
bool visit[50'001];
std::vector<int> prime;
void euler(int n) {
    visit[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!visit[i])
            prime.push_back(i);
        for (int j : prime) {
            if (j * i > n)
                break;
            visit[j * i] = true;
            if (i % j == 0)
                break;
        }
    }
}

void solve() {
    std::cin >> d >> lcm;
    if (lcm % d != 0) {
        std::cout << 0 << '\n';
    } else {
        x = lcm / d;
        cnt = 0, cur = 0;
        while (x > 1) {
            if (x % prime[cur] == 0) {
                cnt++;
                while (x % prime[cur] == 0)
                    x /= prime[cur];
            }
            cur++;
        }
        std::cout << (1 << cnt) << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    euler(50000);
    solve();

    return 0;
}