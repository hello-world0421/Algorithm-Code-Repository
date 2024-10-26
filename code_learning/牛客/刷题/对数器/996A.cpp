#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull quick_power1(ull a, ull b, ull p)
{
    ull ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

ull quick_power2(ull a, ull b, ull p)
{
    ull ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans % p;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);

    ull a, b, p;
    int testTimes = 1000000;
    random_device rd;  // 用于获取随机种子
    mt19937 gen(rd()); // 使用 Mersenne Twister 算法

    // 定义一个均匀分布
    ll v = 1e9;
    uniform_int_distribution<> dis1(0, v); // 分布范围从 0 到 v
    uniform_int_distribution<> dis2(1, v); // 分布范围从 1 到 v

    cout << "Test begin:" << '\n';
    while (testTimes--)
    {
        a = dis1(gen);
        b = dis1(gen);
        p = dis2(gen);
        int ans1 = quick_power1(a, b, p);
        int ans2 = quick_power2(a, b, p);
        if (ans1 != ans2)
        {
            cout << "wrong! " << '\n';
            cout << a << ' ' << b << ' ' << p << '\n';
        }
    }
    cout << "Test end. " << '\n';

    return 0;
}