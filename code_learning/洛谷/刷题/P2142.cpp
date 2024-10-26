#include <bits/stdc++.h>
using namespace std;

string deduction(string num1, string num2)
{
    int n = max((int)num1.size(), (int)num2.size());
    for (int i = 0; i < n; i++)
    {
        if (num1[i] - num2[i] < '0' && i + 1 < num1.size())
        {
            num1[i + 1]--;
            num1[i] = '9' - num2[i] + '1';
        }
        // else if
        // {
        //     num1 = 
        // }
        else
            num1[i] = num2[i] - num1[i] + '0';
    }
    return num1;
}

int main()
{
    string num1 = "20", num2 = "2";
    cout << deduction(num1, num2);

    return 0;
}