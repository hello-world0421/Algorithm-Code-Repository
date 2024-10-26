for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = 0
    for i in range(len(a)):
        if i == 0:
            continue
        if a[i] < a[i - 1] and a[i] == 1:
            print(-1)
            break
        elif a[i] < a[i - 1]:
            while a[i] < a[i - 1]:
                cnt += 1
                a[i] = a[i] ** 2
    else:
        print(cnt)