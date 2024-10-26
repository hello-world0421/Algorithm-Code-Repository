#include <bits/stdc++.h>
using namespace std;

bool check1(int num, long long time, vector<int> &batteries)
{
    long long sum = 0;
    for (int battery : batteries)
    {
        if (battery >= time)
            num--;
        else
            sum += battery;
        if (sum >= time * num)
            return true;
    }
    return false;
}

long long maxRunTime1(int n, vector<int> &batteries)
{
    long long ans = 0;
    for (long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0ll), mid; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        if (check1(n, mid, batteries))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

bool check2(int num, int time, vector<int> &batteries)
{
    long long sum = 0;
    for (int battery : batteries)
    {
        if (battery > time)
            num--;
        else
            sum += battery;
        if (sum >= time * num)
            return true;
    }
    return false;
}

long long maxRunTime2(int n, vector<int> &batteries)
{
    long long ans = 0, sum = 0;
    int max_num = 0;
    for (int battery : batteries)
    {
        sum += battery;
        max_num = max(max_num, battery);
    }
    if (sum >= max_num * n)
        return sum / n;
    else
        for (int l = 0, r = max_num, mid; l <= r;)
        {
            mid = l + ((r - l) >> 1);
            if (check2(n, mid, batteries))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    return ans;
}

int main()
{
    vector<int> batteries = {3, 3, 3};
    cout << maxRunTime1(2, batteries) << endl;
    cout << maxRunTime2(2, batteries) << endl;

    return 0;
}