n, m, q = map(int, input().split())
security = [[0 for _ in range(m)] for _ in range(n)]
for i in range(q):
    t, c = map(int, input().split())
    if t == 1:
        for i in range(n):
            security[i][c-1] = 1
    else:
        for i in range(m):
            security[c-1][i] = 1
flag = 0
for i in range(n):
    flag += security[i].count(0)
print(flag)
