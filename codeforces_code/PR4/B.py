for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    a, valid = [], True
    for i in range(n - 1 - 2):
        res = b[i] & b[i + 2]
        if b[i + 1] & res != res:
            valid = False
            break
    if valid:
        a.append(b[0])
        for i in range(n - 2):
            a.append(b[i] | b[i + 1])
        a.append(b[-1])
        print(*a)
    else:
        print(-1)