#include <bits/stdc++.h>
using namespace std;

string jia(string num1, string num2)
{
    num1 = reverse(num1);
}

string cheng(string num1, string num2)
{
    string temp[10];
}

void solve()
{
    string num1, num2;
    cin >> num1 >> num2;

    // cout << cheng(num1, num2) << '\n';
    // cout << num1 << ' ' << num2 << '\n';
    cout << jia(num1, num2) << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}