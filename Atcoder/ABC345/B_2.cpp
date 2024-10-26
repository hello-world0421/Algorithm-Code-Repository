#include <bits/stdc++.h>

using namespace std;
// 在C++中除法的结果是数学商，会忽略小数部分
int main(void)
{
    long long X;
    cin >> X;
    if ((X + 9) < 0 and (X + 9) % 10 != 0) {
        cout << (X + 9) / 10 - 1 << endl;
    } else {
        cout << (X + 9) / 10 << endl;
    }

    return 0;
}