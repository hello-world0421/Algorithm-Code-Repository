// cool!!! 
// 这种做法太酷了！！！
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-9;

int n;
vector<ld> v;

void solve()
{
    // 读入数据
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;

    // 保证后面取 log(log()) 的时候不出错
    // 删除开头的 1
    reverse(v.begin(), v.end());
    while (v.size() && v.back() == 1)
        v.pop_back();
    reverse(v.begin(), v.end());

    // 特判
    for (auto i : v)
        if (i == 1)
        {
            cout << "-1\n";
            return;
        }

    for (auto &i : v)
        i = log(log(i));

    ll ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ld need = v[i - 1] - v[i];
        if (need > eps)
        {
            int cnt = 1 + (need - eps) / log(2);
            ans += cnt;
            v[i] += cnt * log(2);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}