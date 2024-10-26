#include <iostream>
#include <cmath>

using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return (b == 0 ? a : gcd(b, a % b));
}

struct Fraction {
    i64 up, down;

    Fraction(i64 num = 0, i64 denom = 1) : up(num), down(denom) {
        reduce();
    }

    double toDouble() const {
        return 1.0 * up / down;
    }

    void print() const {
        std::cout << up << ' ' << down << '\n';
    }

    void reduce() {
        if (down < 0) {
            up *= -1; down *= -1;
        }

        if (up == 0) {
            down = 1;
        } else {
            i64 d = gcd(std::abs(up), std::abs(down));
            up /= d; down /= d;
        }
    }

    Fraction& operator += (const Fraction& other) {
        i64 newUp = up * other.down + other.up * down;
        i64 newDown = down * other.down;
        up = newUp;
        down = newDown;
        reduce();
        return *this;
    }

    Fraction& operator -= (const Fraction& other) {
        i64 newUp = up * other.down - other.up * down;
        i64 newDown = down * other.down;
        up = newUp;
        down = newDown;
        reduce();
        return *this;
    }

    Fraction& operator *= (const Fraction& other) {
        up *= other.up;
        down *= other.down;
        reduce();
        return *this;
    }

    Fraction& operator /= (const Fraction& other) {
        up *= other.down;
        down *= other.up;
        reduce();
        return *this;
    }

    friend Fraction operator + (const Fraction& a, const Fraction& b) {
        Fraction result(a);
        return result += b;
    }

    friend Fraction operator - (const Fraction& a, const Fraction& b) {
        Fraction result(a);
        return result -= b;
    }

    friend Fraction operator * (const Fraction& a, const Fraction& b) {
        Fraction result(a);
        return result *= b;
    }

    friend Fraction operator / (const Fraction& a, const Fraction& b) {
        Fraction result(a);
        return result /= b;
    }

    friend bool operator > (const Fraction& a, const Fraction& b) {
        return a.toDouble() > b.toDouble();
    }

    friend bool operator < (const Fraction& a, const Fraction& b) {
        return a.toDouble() < b.toDouble();
    }
};

Fraction n;

Fraction func(const Fraction& t, const Fraction& c) {
    return c / Fraction(2, 1) + t / c - Fraction(1, 2);
}

void solve() {
    std::cin >> n.up;
    Fraction l, r;
    r.up = std::ceil(std::sqrt((Fraction(2, 1) * n).toDouble()));
    l.up = r.up - 1;
    l = func(n, l), r = func(n, r);
    l > r ? r.print() : l.print();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}