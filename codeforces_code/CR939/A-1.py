import sys, os, io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    k, q = map(int, input().split())
    a = list(map(int, input().split()))
    n = list(map(int, input().split()))
    ans0 = []
    for m in n:
        x = [i for i in range(m + 1)]
        while True:
            y, j, c = [], 0, 0
            for i in x:
                if a[j] ^ c:
                    y.append(i)
                else:
                    j += 1
                if j == k:
                    break
                c += 1
            if len(x) == len(y):
                ans1 = len(x) - 1
                ans0.append(ans1)
                break
            x = y
    ans.append(" ".join(map(str, ans0)))
sys.stdout.write("\n".join(ans))

# import sys
# from itertools import accumulate

# t = int(input())
# ans = []

# for _ in range(t):
#     k, q = map(int, input().split())
#     a = list(map(int, input().split()))
#     n = list(map(int, input().split()))
#     ans0 = []

#     for m in n:
#         x = list(range(m + 1))
#         c = list(accumulate(a))

#         for j in range(k):
#             x = [i for i in x if (a[j] ^ c[i % (j + 1)])]
#             if len(x) == 1:
#                 ans0.append(len(x) - 1)
#                 break

#     ans.append(" ".join(map(str, ans0)))

# sys.stdout.write("\n".join(ans))
