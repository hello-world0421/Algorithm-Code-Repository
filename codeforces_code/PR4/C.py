for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    ok = True
    for _ in range(50):
        rate = (max(a) + min(a)) // 2
        if a.count(0) == len(a):
            break
        if rate == 0 and 1 in a:
            ok = False
            break
        ans.append(rate)
        for i in range(len(a)):
            a[i] = abs(a[i] - rate)
    if ok:
        print(len(ans))
        print(*ans)
    else:
        print(-1)
