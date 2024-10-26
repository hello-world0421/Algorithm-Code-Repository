for _ in range(int(input())):
    n, k, m = map(int, input().split())
    a = list(map(int, input().split()))
    pot = [False] * (k + 1) # 锅里的食材
    res = [0] * (n) # 每位游客的满意分

    for i in range(2 * n):
        if pot[a[i % n]]:
            res[i % n] += 1
            pot[a[i % n]] = False
        else:
            pot[a[i % n]] = True

    for i in range(n):
        res[i] *= (m // (2 * n))

    for i in range(m % (2 * n)):
        if pot[a[i % n]]:
            res[i % n] += 1
            pot[a[i % n]] = False
        else:
            pot[a[i % n]] = True
    print(*res)