for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.remove(max(a))
    ans = 0
    for num in a:
        if num == 1:
            ans += 1
        elif num > 1:
            ans += num * 2 - 1
    print(ans)