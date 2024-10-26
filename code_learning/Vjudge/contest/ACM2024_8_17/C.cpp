#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int vis[N];
int ru[N];
vector<int>v[N];
vector<int>out;
int flag = 0;
void com(string s1, string s2) {
    bool flag1 = false;
    int len = min(s1.length(), s2.length());
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            flag1 = true;
            ru[s2[i] - 'a']++;
            v[s1[i] - 'a'].push_back(s2[i] - 'a');
            return;
        }  
    }
    if (!flag1 && s1.length() > s2.length())flag = 1;
}
void solve() {
    int n; cin >> n;
    string s[N];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        com(s[i], s[i + 1]);
    }
    queue<int>q;
    for (int i = 0; i < 26; i++) {
        if (ru[i] == 0) { q.push(i); vis[i] = 1;}
    }
    while (q.size()) {
        int fro = q.front();
        q.pop();
        out.push_back(fro);
        for (int i = 0; i < v[fro].size(); i++) {
            int mid = v[fro][i];
            ru[mid]--;
            if (ru[mid] == 0) { q.push(mid);}
        }
    }
    if (out.size() != 26||flag) {
        cout << "Impossible";
        return;
    }
    for (int i = 0; i < out.size(); i++) { printf("%c", 'a' + out[i]); }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}