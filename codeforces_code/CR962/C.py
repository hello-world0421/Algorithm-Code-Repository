for _ in range(int(input())):
    n, q = map(int, input().split())
    a = input()
    b = input()
    for _ in range(q):
        l, r = map(int, input().split())
        l, r = l - 1, r - 1
        ans, temp = 0, list(b)
        for i in range(l, r + 1):
            for j in range(l, r + 1):
                if a[i] == temp[j]:
                    temp[j] = '#'
                    break
            else:
                ans += 1
        print(ans)