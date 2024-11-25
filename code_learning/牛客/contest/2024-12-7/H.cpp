#include <bits/stdc++.h>
using i64 = long long;

std::vector<int> add(std::vector<int>& A, std::vector<int>& B) {
    if (A.size() < B.size()) return add(B, A);
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

void solve() {
    int n; std::cin >> n;
    std::vector<int> A, B;
    std::string SA, SB; std::cin >> SA;
    for (int i = SA.size() - 1; i >= 0; i--) A.push_back(SA[i] - '0');
    for (int i = 1; i < n; i++) {
        std::cin >> SB;
        for (int j = SB.size() - 1; j >= 0; j--) B.push_back(SB[j] - '0');
        A = add(A, B);
        B.clear();
    }

    for (int i = A.size() - 1; i >= 0; i--) std::cout << A[i];
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}