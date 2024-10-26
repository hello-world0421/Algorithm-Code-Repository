#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    set<int> se;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n && se.size() != n; i++)
        for (int j = 0; i + j * k <= n; j++)
            if (!se.count(i + j * k))
            {
                se.insert(i + j * k);
                v.push_back(i + j * k);
            }
    for (int i = 0; i < v.size(); i++)
        if (i != v.size() - 1)
        {
            cout << v[i] << " ";
        }
        else
            cout << v[i];
    return 0;
}