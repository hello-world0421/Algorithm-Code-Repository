for _ in range(int(input())):
    n, k = map(int,input().split())
    s = []
    for _ in range(n):
        s.append(input())
    for i in range(0, n, k):
        for j in range(0, n, k):
            print(s[i][j], end='')
        print()