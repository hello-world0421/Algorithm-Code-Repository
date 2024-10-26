#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, [](string s1, string s2) {
        return s1 + s2 > s2 + s1;
        });
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }

    return 0;
}