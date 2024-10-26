#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sex[n];
    string name[n];
    for (int i = 0; i < n; i++) {
        cin >> sex[i] >> name[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (sex[i] != sex[j] && sex[j] <= 1) {
                cout << name[i] << " " << name[j] << endl;
                sex[j] += 2;
                break;
            }
        }
    }

    return 0;
}