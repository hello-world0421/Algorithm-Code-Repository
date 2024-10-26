for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()

    cnt = 0
    taken = [False] * n

    for i in range(n):
        if b[i] == '0':
            continue
        for j in range(i - 1, i + 2):
            if j < 0 or j >= n:
                continue
            if i == j and a[j] == '0':
                cnt += 1
            elif i != j and a[j] == '1' and not taken[j]:
                cnt += 1
                taken[j] = True
                break
    print(cnt)