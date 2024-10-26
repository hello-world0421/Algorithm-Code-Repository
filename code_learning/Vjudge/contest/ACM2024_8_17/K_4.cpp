#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SolutionResult {
    bool found;
    ll a, b, c;
};

ll d[3];

bool check(ll a, ll b, ll c) {
    ll d[3] = { a, b, c };
    sort(d, d + 3);
    return (d[0] + d[1] > d[2]);
}

void solve1(ll a, ll b, ll c) {
    // ...
}

SolutionResult solve2(ll a, ll b, ll c) {
    // ...
    if (found) {
        return { true, d[0], d[1], d[2] };
    }
    return { false, 0, 0, 0 };
}

SolutionResult solve3(ll a, ll b, ll c) {
    // ...
    if (found) {
        return { true, d[0], d[1], d[2] };
    }
    return { false, 0, 0, 0 };
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    d[0] = 149, d[1] = 261, d[2] = 401;
    solve1(d[0], d[1], d[2]);

    int res = 0;
    int max_iterations = 1000;
    while (check(d[0], d[1], d[2]) && res == 0 && max_iterations-- > 0) {
        if ((d[0] ^ d[1] ^ d[2]) != 0) {
            auto result = solve2(d[0], d[1], d[2]);
            if (result.found) {
                cout << result.a << ' ' << result.b << ' ' << result.c << endl;
                res = 1;
            }
        } else {
            auto result = solve3(d[0], d[1], d[2]);
            if (result.found) {
                cout << result.a << ' ' << result.b << ' ' << result.c << endl;
                res = 1;
            }
        }
    }

    return 0;
}