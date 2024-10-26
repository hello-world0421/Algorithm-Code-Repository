def MAD():
    global a, c, n
    for i in range(n + 1):
        c[i] = False
    maxu = 0
    for i in range(n):
        if c[a[i]]:
            maxu = max(maxu, a[i])
        else:
            c[a[i]] = True
        a[i] = maxu

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c = [False] * (n + 1)
    ans = sum(a)
    MAD()
    ans += sum(a)
    MAD()
    for i in range(n):
        ans += (n - i) * a[i]
    print(ans)