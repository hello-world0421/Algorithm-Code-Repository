import sys, os, io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    s, m = 0, 2 * n
    for i in range(1, n + 1):
        s += (i * i - (i - 1) * (i - 1)) * i
    ans.append(" ".join(map(str, (s, m))))
    p = [i for i in range(n, 0, -1)]
    p = " ".join(map(str, p))
    ans0 = []
    c = 1
    for i in range(2, 2 * (n + 1)):
        ans0.append(" ".join((str(c), str(i >> 1), p)))
        c ^= 3
    ans.append("\n".join(ans0))
sys.stdout.write("\n".join(ans))

# import sys

# t = int(input())
# ans = []
# for _ in range(t):
#     n = int(input())
#     s = sum((i * i - (i - 1) * (i - 1)) * i for i in range(1, n + 1))
#     m = 2 * n
#     ans.append(f"{s} {m}")

#     p = " ".join(map(str, range(n, 0, -1)))
#     # ans0 = [" ".join((str((i >> 1) % 3 + 1), str(i >> 1), " ".join(p))) for i in range(2, 2 * (n + 1))]
#     ans0 = [f"{c} {i >> 1} {p}" for c, i in zip(range(1, 2 * (n + 1), 2), range(2, 2 * (n + 1)))]
#     ans.append("\n".join(ans0))

# sys.stdout.write("\n".join(ans))
