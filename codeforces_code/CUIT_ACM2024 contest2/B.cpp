#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n); // 每个人想要的食材
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> res(2 * n + 1, 0); // 两轮游戏的结果
    vector<bool> pot(n, false);    // 锅里面的食材

    if(m<2*n&&m>n){
    for (int i = 0; i <  n; i++)
    {
        if (pot[a[i]])
        {
            res[i] ++;
            pot[a[i]] = false;
        }
        else
        {
            pot[a[i]] = true;
        }
    }
    for (int i = 0; i < m-n; i++)
    {
        if (pot[a[i]])
        {
            res[i]++;
            pot[a[i]] = false;
        }
        else
        {
            pot[a[i]] = true;
        }
    }
    }else{
        int p = m / n, q = m % n;
    if(p%2==0){
        for (int i = 0; i < 2 * i;i++){
            res[i] *= (p/2);
        }
        for (int i = 0; i < p;i++){
            if (pot[a[i]])
            {
                res[i]++;
                pot[a[i]] = false;
            }
            else
            {
                pot[a[i]] = true;
            }
        }
    }
    else{
        for (int i = 0; i < 2 * i;i++){
            res[i] *= (p /2);
        }
        for (int i = 0; i < n; i++)
        {
            if (pot[a[i]])
            {
                res[i]++;
                pot[a[i]] = false;
            }
            else
            {
                pot[a[i]] = true;
            }
        }
        for (int i = 0; i < p; i++)
        {
            if (pot[a[i]])
            {
                res[i]++;
                pot[a[i]] = false;
            }
            else
            {
                pot[a[i]] = true;
            }
        }
    }
}
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return ;
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}