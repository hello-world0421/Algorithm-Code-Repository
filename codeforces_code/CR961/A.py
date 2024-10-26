for _ in range(int(input())):
    n, k = map(int, input().split())
    if k == 0:
        print(0)
    elif k <= n:
        print(1)
    else:
        ans = 1
        k -= n
        while (n - 1 >= 1):
            n -= 1
            for _ in range(2):
                k -= n
                ans += 1
                if k > 0:
                    continue
                else:
                    break
            if k <= 0:
                break
        print(ans)