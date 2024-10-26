#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-9;

int main()
{
    int n;
    cin >> n;
    bool flag = 1;
    vector<vector<double>> a(n, vector<double>(n));
    vector<vector<double>> a_1(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i == j)
                a_1[i][j] = 1;
        }
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[k][i]))
                k = j;
        if (abs(a[k][i]) < EPS)
        {
            cout << "No Solution";
            flag = 0;
            break;
        }
        swap(a[i], a[k]);
        swap(a_1[i], a_1[k]);
        for (int j = i + 1; j < n; j++)
        {
            a[i][j] /= a[i][i];
            a_1[i][j] /= a[i][i];
        }
        a_1[i][i] /= a[i][i];
        a[i][i] = 1;
        for (int j = 0; j < n; j++)
            if (j != i && abs(a[j][i]) > EPS)
            {
                for (int k = i + 1; k < n; k++)
                {
                    a[j][k] -= a[i][k] * a[j][i];
                    a_1[j][k] -= a_1[i][k] * a[j][i];
                }
                a_1[j][i] -= a_1[i][i] * a[j][i];
                a[j][i] = 0;
            }
    }
    if (flag)
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a_1[i][j] << ' ';
            }
            cout << '\n';
        }

    return 0;
}