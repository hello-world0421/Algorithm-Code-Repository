#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] != '<') {
        cout << "No" << endl;
        return 0;
    }
    if (s[n-1] != '>') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < n-1; i++) {
        if (s[i] != '=') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}