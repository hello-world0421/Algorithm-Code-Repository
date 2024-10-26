#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 100;
const int LEN = 1004;

ll a[LEN], b[LEN], c[LEN];

void clear(ll a[])
{
    for (int i = 0; i < LEN; i++)
        a[i] = 0;
}

void read(ll a[])
{
    static char s[LEN + 1];
    scanf("%s", s);

    clear(a);

    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[len - i - 1] = s[i] - '0';
}

void print(ll a[])
{
    int i;
    for (i = LEN - 1; i >= 1; i--)
        if (a[i] != 0)
            break;
    for (; i >= 0; i--)
        // putchar(a[i] + '0');
        cout << a[i] << ' ';
    putchar('\n');
}

// 这里的 a,b,c 数组均为 p 进制下的数
// 最终输出答案时需要将数字转为十进制
void add(ll a[], ll b[], ll c[])
{
    clear(c);

    for (int i = 0; i < LEN - 1; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= p)
        { // 在普通高精度运算下，p=10
            c[i + 1] += 1;
            c[i] -= p;
        }
    }
}

void convertToDecimal(ll a[], ll b[])
{
    clear(b);

    ll power = 1;
    for (int i = 0; i < LEN - 1; i++)
    {
        b[i + 1] += a[i] / 10;
        b[i] = a[i] % 10;
    }
}

// 完整模板和实现 https://baobaobear.github.io/post/20210228-bigint1/
// 对b乘以mul再左移offset的结果相减，为除法服务
BigIntSimple &sub_mul(const BigIntSimple &b, int mul, int offset)
{
    if (mul == 0)
        return *this;
    int borrow = 0;
    // 与减法不同的是，borrow可能很大，不能使用减法的写法
    for (size_t i = 0; i < b.v.size(); ++i)
    {
        borrow += v[i + offset] - b.v[i] * mul - BIGINT_BASE + 1;
        v[i + offset] = borrow % BIGINT_BASE + BIGINT_BASE - 1;
        borrow /= BIGINT_BASE;
    }
    // 如果还有借位就继续处理
    for (size_t i = b.v.size(); borrow; ++i)
    {
        borrow += v[i + offset] - BIGINT_BASE + 1;
        v[i + offset] = borrow % BIGINT_BASE + BIGINT_BASE - 1;
        borrow /= BIGINT_BASE;
    }
    return *this;
}

BigIntSimple div_mod(const BigIntSimple &b, BigIntSimple &r) const
{
    BigIntSimple d;
    r = *this;
    if (absless(b))
        return d;
    d.v.resize(v.size() - b.v.size() + 1);
    // 提前算好除数的最高三位+1的倒数，若最高三位是a3,a2,a1
    // 那么db是a3+a2/base+(a1+1)/base^2的倒数，最后用乘法估商的每一位
    // 此法在BIGINT_BASE<=32768时可在int32范围内用
    // 但即使使用int64，那么也只有BIGINT_BASE<=131072时可用（受double的精度限制）
    // 能保证估计结果q'与实际结果q的关系满足q'<=q<=q'+1
    // 所以每一位的试商平均只需要一次，只要后面再统一处理进位即可
    // 如果要使用更大的base，那么需要更换其它试商方案
    double t = (b.get((unsigned)b.v.size() - 2) +
                (b.get((unsigned)b.v.size() - 3) + 1.0) / BIGINT_BASE);
    double db = 1.0 / (b.v.back() + t / BIGINT_BASE);
    for (size_t i = v.size() - 1, j = d.v.size() - 1; j <= v.size();)
    {
        int rm = r.get(i + 1) * BIGINT_BASE + r.get(i);
        int m = std::max((int)(db * rm), r.get(i + 1));
        r.sub_mul(b, m, j);
        d.v[j] += m;
        if (!r.get(i + 1)) // 检查最高位是否已为0，避免极端情况
            --i, --j;
    }
    r.trim();
    // 修正结果的个位
    int carry = 0;
    while (!r.absless(b))
    {
        r.subtract(b);
        ++carry;
    }
    // 修正每一位的进位
    for (size_t i = 0; i < d.v.size(); ++i)
    {
        carry += d.v[i];
        d.v[i] = carry % BIGINT_BASE;
        carry /= BIGINT_BASE;
    }
    d.trim();
    d.sign = sign * b.sign;
    return d;
}

BigIntSimple operator/(const BigIntSimple &b) const
{
    BigIntSimple r;
    return div_mod(b, r);
}

BigIntSimple operator%(const BigIntSimple &b) const
{
    BigIntSimple r;
    div_mod(b, r);
    return r;
}

int main()
{
    read(a);
    read(b);
    add(a, b, c);
    convertToDecimal(c, a);
    print(a);

    return 0;
}