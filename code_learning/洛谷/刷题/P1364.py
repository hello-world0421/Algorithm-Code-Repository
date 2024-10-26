import sys
from math import inf
input = lambda: sys.stdin.readline().rstrip()

ans = inf
n = int(input())
adj = {num: (0, 0, 0) for num in range(0, n + 1)}

for i in range(1, n + 1):
    w, u, v = map(int, input().split())
    adj[i] = (w, u, v)

dep = [0] * (n + 1)
fa = [[0] * 30 for _ in range(n + 1)]

def dfs(p, fath):
    if p == 0:
        return
    dep[p] = dep[fath] + 1
    fa[p][0] = fath
    i = 1
    while (1 << i) <= dep[p]:
        fa[p][i] = fa[fa[p][i - 1]][i - 1]
        i += 1
    for i in (1, 2):
        dfs(adj[p][i], p)

def lca(a, b):
    if dep[a] < dep[b]:
        a, b = b, a
    for i in range(28, -1, -1):
        if dep[a] - (1 << i) >= dep[b]:
            a = fa[a][i]
    if a == b:
        return a
    
    for i in range(28, -1, -1):
        if fa[a][i] != fa[b][i]:
            a, b = fa[a][i], fa[b][i]
    return fa[a][0]
dfs(1, 0)

ans_index = 0
for i in range(1, n + 1):
    res = 0
    for j in range(1, n + 1):
        res += (dep[i] + dep[j] - 2 * dep[lca(i, j)]) * adj[j][0]
    ans = min(ans, res)

sys.stdout.write(str(ans))