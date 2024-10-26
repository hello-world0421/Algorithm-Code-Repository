n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))


def match(x):
    for i in range(1, m + 1):
        if adj[x][i] and not vis[i]:
            vis[i] = True
            if p[i] == 0 or match(p[i]):
                p[i] = x
                return True
    return False

adj = [[False] * (m + 1) for _ in range(n + 1)]

for i in range(n):
    for j in range(m):
        if -1 <= a[i] - b[j] <= 1:
            adj[i + 1][j + 1] = True

p = [0] * (m + 1)

cnt = 0
for i in range(1, n + 1):
    vis = [False] * (m + 1)
    if match(i):
        cnt += 1
print(cnt)