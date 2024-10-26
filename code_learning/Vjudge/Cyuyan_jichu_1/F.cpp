#include <bits/stdc++.h>

using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int fishs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> fishs[i];
    }
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < i; j++)
        {
            if (fishs[j] < fishs[i])
                num++;
        }
        cout << num;
        if (i != n-1)
            cout << ' ';
    }

    return 0;
}