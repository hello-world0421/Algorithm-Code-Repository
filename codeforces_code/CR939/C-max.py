import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    m = n << 1
    s = sum(i * (2 * i - 1) for i in range(1, n + 1))
    ans.append(' '.join(map(str, [s, m])))
    p = [i for i in range(n, 0, -1)]
    p = ' '.join(map(str, p))
    ans0 = []
    c = 1
    for i in range(2, 2 * (n + 1)):
        ans0.append(' '.join((str(c), str(i >> 1), p)))
        c ^= 3
    ans.append('\n'.join(ans0))

sys.stdout.write('\n'.join(ans))
