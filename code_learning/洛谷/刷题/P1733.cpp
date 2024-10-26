#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int l = 1, r = 1e9, mid, ans; l <= r;)
    {
        mid = l + ((r - l) >> 1);
        cout << mid << endl;
        cin >> ans;
        if (ans == 0)
            return 0;
        else if (ans == 1)
            r = mid - 1;
        else if (ans == -1)
            l = mid + 1;
    }
    return 0;
}