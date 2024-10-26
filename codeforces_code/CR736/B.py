# Hopcroft-Karp 算法 目前还不会
for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()

    def match(x):
        for i in range(1, n + 1):
            if adj[x][i] and not vis[i]:
                vis[i] = True
                if p[i] == 0 or match(p[i]):
                    p[i] = x
                    return True
        return False

    adj = [[False] * (n + 1) for i in range(n + 1)]

    for i in range(n):
        if b[i] == '0':
            continue
        for j in range(i - 1, i + 2):
            if j < 0 or j >= n:
                continue
            if (i == j and a[j] == '0') or ((i - j == 1 or i - j == -1) and a[j] == '1'):
                adj[i + 1][j + 1] = True

    p = [0] * (n + 1)

    cnt = 0
    for i in range(1, n + 1):
        vis = [False] * (n + 1)
        if match(i):
            cnt += 1
    print(cnt)