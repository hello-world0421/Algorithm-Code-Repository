#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 1;
int height[MAXN], power[MAXN], stack[MAXN], res[MAXN][2];
int n, r, ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> height[i] >> power[i];
    r = 0;
    int cur;
    for (int i = 0; i < n; i++)
    {
        while (r > 0 && height[stack[r - 1]] <= height[i])
        {
            cur = stack[--r];
            res[cur][0] = r > 0 ? stack[r - 1] : -1;
            res[cur][1] = i;
        }
        stack[r++] = i;
    }
    while (r > 0)
    {
        cur = stack[--r];
        res[cur][0] = r > 0 ? stack[r - 1] : -1;
        res[cur][1] = i;
    }

        return 0;
}