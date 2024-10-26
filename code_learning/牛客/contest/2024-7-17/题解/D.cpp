#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
using namespace std;
using ll = long long;
const int N = 4e5 + 7;
const int mod = 998244353;
ll f(ll x, ll k)
{
    ll y = 1ll << (k + 1);  // 循环周期
    ll ok = y / 2;  // 循环周期值
    x++;  // 为了更好的处理边界情况
    ll res = x / y * ok; // 循环节内部分
    ll r = x % y;  // 循环节多余部分
    r -= ok;  // 判断多余部分是在循环的前半部分还是后半部分
    if (r > 0)
        res += r; // 计算循环节多余部分
    return res;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (ll i = 61; i >= 0; i--)
    {
        ll p = (f(r, i) % mod - f(l - 1, i) % mod + mod) % mod;  // 直接做减法结果可能是负数，所以在最后加一个 mod
        ans = (ans + p) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}