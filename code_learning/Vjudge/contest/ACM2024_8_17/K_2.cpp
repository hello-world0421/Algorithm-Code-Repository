#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve1(ll a, ll b, ll c) {
    ll d[3] = { a, b, c };
    sort(d, d + 3);
    for (int i = 0; i < 2; i++) {
        if (d[i] == d[i + 1]) {
            return (d[0] != 1 ? 1 : 0);
        }
    }
    int num = 0;
    while (d[0] + d[1] + d[2] > 5) {
        ll sum = d[0] + d[1] + d[2];
        if (sum <= 5)break;
        if (d[0] == 1)break;
        d[2] = d[1] - d[0] + 1;
        num++;
        sort(d, d + 3);
    }
    return (num % 2 != 0 ? 1 : 0);
}

int solve2(ll a, ll b, ll c) {
    return (((a - 1) ^ (b - 1) ^ (c - 1)) != 0 ? 1 : 0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll d[3];
    int testTimes = 10;
    random_device rd;  // 用于获取随机种子
    mt19937 gen(rd()); // 使用 Mersenne Twister 算法

    // 定义一个均匀分布
    ll v = 100;
    uniform_int_distribution<> dis(1, v); // 分布范围从 1 到 v

    int cnt = 0;
    cout << "Test begin:" << '\n';
    while (testTimes--) {
        d[0] = dis(gen);
        d[1] = dis(gen);
        d[2] = dis(gen);
        sort(d, d + 3);
        while (d[0] + d[1] <= d[2]) {
            d[0] = dis(gen);
            d[1] = dis(gen);
            d[2] = dis(gen);
            sort(d, d + 3);
        }
        int ans1 = solve1(d[0], d[1], d[2]);
        int ans2 = solve2(d[0], d[1], d[2]);
        if (ans1 != ans2) {
            cout << "wrong! " << '\n';
            // cnt++;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << '\n';
        }
    }
    cout << "Test end. " << '\n';
    // cout << cnt << '/' << testTimes << '\n';

    return 0;
}