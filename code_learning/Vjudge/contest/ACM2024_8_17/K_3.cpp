#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[3];

bool check(ll a, ll b, ll c) {
    ll d[3] = { a, b, c };
    sort(d, d + 3);
    return (d[0] + d[1] > d[2] ? true : false);
}

void solve1(ll a, ll b, ll c) {
    ll d[3] = { a, b, c };
    sort(d, d + 3);
    for (int i = 0; i < 2; i++) {
        if (d[i] == d[i + 1]) {
            if (d[0] != 1)cout << "Win" << endl;
            else cout << "Lose" << endl;
            return;
        }
    }
    int num = 0;
    while (d[0] + d[1] + d[2] > 5) {
        cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
        ll sum = d[0] + d[1] + d[2];
        if (sum <= 5)break;
        if (d[0] == 1)break;
        d[2] = d[1] - d[0] + 1;
        num++;
        sort(d, d + 3);
    }
    cout << num << endl;
    if (num % 2 != 0)cout << "Win" << endl;
    else cout << "Lose" << endl;
}

int solve2(ll a, ll b, ll c) {
    for (int i = a - 1; i >= 1; i--) {
        if (check(a - i, b, c) && ((a - i - 1) ^ (b - 1) ^ (c - 1)) == 0) {
            d[0] = a - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    for (int i = b - 1; i >= 1; i--) {
        if (check(a, b - i, c) && ((a - 1) ^ (b - i - 1) ^ (c - 1)) == 0) {
            d[1] = b - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    for (int i = c - 1; i >= 1; i--) {
        if (check(a, b, c - i) && ((a - 1) ^ (b - 1) ^ (c - i - 1)) == 0) {
            d[2] = c - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    return -1;
}

int solve3(ll a, ll b, ll c) {
    for (int i = a - 1; i >= 0; i--) {
        if (check(a - i, b, c) && ((a - i - 1) ^ (b - 1) ^ (c - 1)) != 0) {
            d[0] = a - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    for (int i = b - 1; i >= 0; i--) {
        if (check(a, b - i, c) && ((a - 1) ^ (b - i - 1) ^ (c - 1)) != 0) {
            d[1] = b - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    for (int i = c - 1; i >= 0; i--) {
        if (check(a, b, c - i) && ((a - 1) ^ (b - 1) ^ (c - i - 1)) != 0) {
            d[2] = c - i;
            cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            return 0;
        }
    }
    return -1;
}

int main() {
    // solve1(253, 261, 401);
    // 37 62 63
    // d[0] = 37, d[1] = 62, d[2] = 63;
    // int res = 0, cnt = 0;
    // cout << "first: " << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
    // while (check(d[0], d[1], d[2]) && res == 0) {
    //     cout << ((++cnt & 1) == 0 ? "first: " : "second: ");
    //     if (((d[0] - 1) ^ (d[1] - 1) ^ (d[2] - 1)) != 0) {
    //         res = solve2(d[0], d[1], d[2]);
    //     } else {
    //         res = solve3(d[0], d[1], d[2]);
    //     }
    //     if (res == -1) {
    //         cout << "win!!";
    //     }
    // }
    int res = 0, cnt = 0;
    cin >> d[0] >> d[1] >> d[2];
    cout << "first: " << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
    while (check(d[0], d[1], d[2]) && res == 0) {
        cout << ((++cnt & 1) == 0 ? "first: " : "second: ");
        if (((d[0] - 1) ^ (d[1] - 1) ^ (d[2] - 1)) != 0) {
            res = solve2(d[0], d[1], d[2]);
        } else {
            res = solve3(d[0], d[1], d[2]);
        }
        if (res == -1) {
            cout << "win!!";
        }
        cout << ((++cnt & 1) == 0 ? "first: " : "second: ");
        cin >> d[0] >> d[1] >> d[2];
        // cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
    }

    return 0;
}