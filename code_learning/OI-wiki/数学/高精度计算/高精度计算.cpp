#include <bits/stdc++.h>
using namespace std;
const int LEN = 1004;

int a[LEN], b[LEN], c[LEN];

// 读入高精度代码
void clear(int a[])
{
    for (int i = 0; i < LEN; i++)
        a[i] = 0;
}

void read(int a[])
{
    static char s[LEN + 1];
    scanf("%s", s);

    clear(a);

    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[len - i - 1] = s[i] - '0';
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; i--)
        if (a[i] != 0)
            break;
    for (; i >= 0; i--)
        putchar(a[i] + '0');
    putchar('\n');
}

void add(int a[], int b[], int c[])
{
    clear(c);

    // 高精度实现中，一般令数组的最大长度 LEN 比可能的输入大一些
    // 然后略去末尾的几次循环，这样一来可以省去不少边界情况的处理
    for (int i = 0; i < LEN - 1; ++i)
    {
        // 将相应位上的数码相加
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            // 进位
            c[i + 1] += 1;
            c[i] -= 10;
        }
    }
}

void sub(int a[], int b[], int c[])
{
    clear(c);

    for (int i = 0; i < LEN - 1; ++i)
    {
        // 逐位相减
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            // 借位
            c[i + 1] -= 1;
            c[i] += 10;
        }
    }
}

void mul_short(int a[], int b, int c[])
{
    clear(c);

    for (int i = 0; i < LEN - 1; ++i)
    {
        // 直接把 a 的第 i 位数码乘以乘数，加入结果
        c[i] += a[i] * b;

        if (c[i] >= 10)
        {
            // 处理进位
            // c[i] / 10 即除法的商数成为进位的增量值
            c[i + 1] += c[i] / 10;
            // 而 c[i] % 10 即除法的余数成为在当前位留下的值
            c[i] %= 10;
        }
    }
}

void mul(int a[], int b[], int c[])
{
    clear(c);

    for (int i = 0; i < LEN - 1; i++)
    {
        // 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
        // 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
        // 这样做的效果和直接进行上图的运算最后求和是一样的，只是更加简短的一种实现方式
        // 将 a 和 b 看作两个多项式，利用卷积求各项系数
        for (int j = 0; j <= i; j++)
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

// 被除数 a 以下标 last_dg 为最低位，是否可以再减去除数 b 而保持非负
// len 是除数 b 的长度，避免反复计算
bool greater_eq(int a[], int b[], int last_dg, int len)
{
    // 有可能被除数剩余的部分比除数长，这个情况下最多多出 1 位，故如此判断即可
    if (a[last_dg + len] != 0)
        return true;
    // 从高位到低位，逐位比较
    for (int i = len - 1; i >= 0; --i)
    {
        if (a[last_dg + i] > b[i])
            return true;
        if (a[last_dg + i] < b[i])
            return false;
    }
    // 相等的情形下也是可行的
    return true;
}

void div(int a[], int b[], int c[], int r[])
{
    clear(c);
    clear(r);

    int la, lb;
    for (la = LEN - 1; la > 0; --la)
        if (a[la - 1] != 0)
            break;
    for (lb = LEN - 1; lb > 0; --lb)
        if (b[lb - 1] != 0)
            break;
    if (lb == 0)
    {
        puts("> <");
        return;
    } // 除数不能为零

    // c 是商
    // r 是被除数的剩余部分，算法结束后自然成为余数
    for (int i = 0; i < la; ++i)
        r[i] = a[i];
    for (int i = la - lb; i >= 0; --i)
        // 计算商的第 i 位
        while (greater_eq(r, b, i, lb))
        {
            // 若可以减，则减
            // 这一段是一个高精度减法
            for (int j = 0; j < lb; ++j)
            {
                r[i + j] -= b[j];
                if (r[i + j] < 0)
                {
                    r[i + j + 1] -= 1;
                    r[i + j] += 10;
                }
            }
            // 使商的这一位增加 1
            c[i] += 1;
            // 返回循环开头，重新检查
        }
}

int main()
{
    read(a);
    read(b);
    mul(a, b, c);
    print(c);

    return 0;
}