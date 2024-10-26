for _ in range(int(input())):
    a = input()
    b = input()
    ans = 0
    for i in range(len(b)):
        k = i
        for j in range(len(a)):
            if k < len(b) and b[k] == a[j]:
                k += 1
        ans = max(ans, k - i)
    print(len(a) + len(b) - ans)