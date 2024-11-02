for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)
    ans = 2
    i, j = 0, 2
    while j < n:
        if a[i] + a[i + 1] > a[j]:
            ans = max(ans, j - i + 1)
            j += 1
        else:
            while a[i] + a[i + 1] <= a[j]:
                if i + 2 <= j:
                    i += 1
                else:
                    i += 1
                    j += 1
    print(n - ans)