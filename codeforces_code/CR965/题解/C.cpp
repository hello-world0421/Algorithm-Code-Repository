#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<pair<int, int>> a(n);
        for (auto& x : a) cin >> x.first;
        for (auto& x : a) cin >> x.second;
        sort(a.begin(), a.end());

        long long ans = 0;
        // case 1 : increment max
        for (int i = 0; i < n; i++) if (a[i].second == 1) {
            // find med(c_i)
            int mc;
            if (i < n / 2) 
        }
    }
}