for _ in range(int(input())):
    n = int(input())
    if n > 12:
        print(0)
        continue
    cnt = 0
    for i in range(1, 7):
        for j in range(i, 7):
            if i + j == n:
                cnt += 1
    print(cnt)