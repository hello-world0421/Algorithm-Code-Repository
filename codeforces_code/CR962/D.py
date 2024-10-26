for _ in range(int(input())):
    n, x = map(int, input().split())
    ans = 0
    for a in range(1, x - 1):
        for b in range(1, x - a):
            l, r = 1, x - a - b
            c = l + ((r - l) >> 1)
            res = 0
            res1, res2 = a * b, a + b
            while (l <= r):
                if res1 + res2 * c <= n:
                    res = c
                    l = c + 1
                else:
                    r = c - 1
                c = l + ((r - l) >> 1)
            ans += c
    print(ans)