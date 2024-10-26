/*
字典树
时间复杂度 O(sum(|s|))
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXLEN = 1e6 + 1;

int n, k;
string s;

int Cnt, triePass[MAXLEN], trieEnd[MAXLEN], trie[MAXLEN][26];

int newNode() {
    Cnt++;
    triePass[Cnt] = trieEnd[Cnt] = 0;
    memset(trie[Cnt], 0, sizeof(trie[Cnt]));
    return Cnt;
}

void add() {
    int now = 1; triePass[now]++;
    for (int i = 0; i < s.length(); i++) {
        int& c = trie[now][s[i] - 'a'];
        if (!c) c = newNode();
        now = c; triePass[now]++;
    }
    trieEnd[now]++;
}

void solve() {
    Cnt = 0; newNode();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        add();
    }

    int now = 1;
    while (true) {
        int t = trieEnd[now];
        for (int i = 0; i < 26; i++) if (triePass[trie[now][i]]) t++;
        if (t >= k) {
            if (now == 1) cout << "EMPTY";
            cout << '\n'; return;
        }

        for (int i = 0; i < 26; i++) if (triePass[trie[now][i]]) {
            t = t - 1 + triePass[trie[now][i]];
            if (t >= k) {
                k -= t - triePass[trie[now][i]];
                now = trie[now][i];
                cout << (char)(i + 'a');
                break;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}