#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, ans = 0;
    vector<long long> cnt(26);
    bool same = false;
    string s;

    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        cnt[((int)(s[i] - 'a'))]++;
    }
    ans = n * n;
    for (int i = 0; i < 26; i++) {
        ans -= cnt[i] * cnt[i];
        if (cnt[i] > 1)
            same = true;
    }
    ans /= 2;
    if (same)
        ans++;
    cout << ans << endl;

    return 0;
}