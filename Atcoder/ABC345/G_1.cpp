#include <iostream>
#include <vector>
using namespace std;

#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;

int N, K;
vector<mint> f; // F = 1/K sum{i=1..K} x^i
vector<mint> a; // (a_0, a_1, ..., a_N)

// input  : l, r, g = (sum{i=0..N-1} x^i) F^l mod x^N
// output : F^{r-l} mod x^N
vector<mint> dc(int l, int r, vector<mint> g)
{
    // int b = g.size();
    int b = min<int>(g.size(), (r - l - 1) * K + 1);
    g.erase(begin(g), begin(g) + g.size() - b);
    if (l + 1 == r)
    {
        a[l] = g.back();
        return f;
    }
    int m = (l + r) / 2;
    auto p = dc(l, m, g);
    g = atcoder::convolution(g, p), g.resize(b);
    auto q = dc(m, r, g);
    auto res = atcoder::convolution(p, q);
    if ((int)res.size() > N)
        res.resize(N);
    return res;
}

int main()
{
    cin >> N >> K;
    a.resize(N + 1);
    f.resize(K + 1);
    for (int i = 1; i <= K; i++)
        f[i] = mint{K}.inv();
    dc(0, N + 1, vector<mint>(N, 1));
    for (int i = 0; i < N; i++)
        cout << (a[i] - a[i + 1]).val() << "\n";
}
