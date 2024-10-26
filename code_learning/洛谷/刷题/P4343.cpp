#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int l, k;
    cin >> l >> k;
    vector<ll> x(l);
    ll max_num = -1;
    for (int i = 0; i < l; i++)
    {
        cin >> x[i];
        max_num = max(max_num, x[i]);
    }

    // 二分答案法的 check 函数
    auto check = [&](ll n)
    {
        ll text = 0, cnt = 0;
        for (int i = 0; i < l; i++)
            if (text + x[i] >= n)
                cnt++, text = 0;
            else
                text = max(0ll, text + x[i]);
        return cnt;
    };

    // 二分求满足条件的最小值
    ll ans1 = -1, mid;
    // n 的最小值保证任意正整数均可以通过
    // n 的最大值保证即使整个列表均为最大值且相加也通过不了
    ll left = 1, right = max_num * l + 1;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        // 结果从右侧逼近
        if (check(mid) <= k)
            ans1 = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    // 二分求满足条件的最大值
    ll ans2 = -1;
    left = 1, right = max_num * l;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        // 结果从左侧逼近 (总之为满足条件与不满足条件之间的临界值)
        if (check(mid) >= k)
            ans2 = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    if (check(ans1) != k || check(ans2) != k)
        cout << -1;
    else
        cout << ans1 << ' ' << ans2;

    return 0;
}