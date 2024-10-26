n, k = map(int, input().split())
adj = {num: [] for num in range(1, n + 1)}

for _ in range(n - 1):
    x, y = map(int, input().split())
    adj[x].append((y, 0))
    adj[y].append((x, 0))

dep = [0] * (n + 1)
fa = [[0] * 30 for _ in range(n + 1)]

def dfs(p, fath):
    dep[p] = dep[fath] + 1
    fa[p][0] = fath
    i = 1
    while (1 << i) <= dep[p]:
        fa[p][i] = fa[fa[p][i - 1]][i - 1]
        i += 1
    for s in adj[p]:
        if s == fath:
            continue
        dfs(s, p)

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
for _ in range(k):
    pass