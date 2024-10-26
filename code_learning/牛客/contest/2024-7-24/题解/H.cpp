#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<string, vector<string>> mp;
    for (int i = 1; i <= n; i++)
    {
        string id;
        cin >> id;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            string mes;
            cin >> mes;
            auto &vec = mp[id];
            bool ok = true;
            for (int t = 0; t < vec.size(); t++)
            {
                string tmp = vec[t];
                if (tmp.size() > mes.size())
                {
                    tmp.erase(0, tmp.size() - mes.size());
                    if (tmp == mes)
                    {
                        ok = false;
                        break;
                    }
                }
                else
                {
                    string ttmp = mes;
                    ttmp.erase(0, mes.size() - tmp.size());
                    if (ttmp == tmp)
                    {
                        ok = false;
                        vec[t] = mes;
                        break;
                    }
                }
            }
            if (ok)
                vec.push_back(mes);
        }
    }
    cout << mp.size() << endl;
    for (auto [key, vec] : mp)
    {
        cout << key << ' ' << vec.size() << ' ';
        sort(vec.begin(), vec.end());
        for (auto e : vec)
            cout << e << ' ';
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}