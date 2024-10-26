from math import ceil, log2

for _ in range(int(input())):
    n = int(input())
    ans = []
    logn = ceil(log2(n))
    if (n - (1 << logn)) != 0:
        for i in range(logn, -1, -1):
            if n & (1 << i):
                ans.append(n - (1 << i))
    ans.append(n)
    print(len(ans))
    print(*ans)