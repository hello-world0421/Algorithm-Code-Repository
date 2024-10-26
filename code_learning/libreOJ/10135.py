import sys


n = int(input())
adj = {}

for _ in range(n):
    x, y = map(int, input().split())
    if y == -1:
        root = x
        continue
    if x in adj.keys():
        adj[x].append(y)
    else:
        adj[x] = [y]
    if y in adj.keys():
        adj[y].append(x)
    else:
        adj[y] = [x]

dep = {num: 0 for num in adj.keys()}
fa = {num: [0] * 30 for num in adj.keys()}

def dfs(p, fath):
    dep[p] = dep.get(fath, 0) + 1
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
        a_1, b_1 = b, a
    else:
        a_1, b_1 = a, b
    for i in range(28, -1, -1):
        if dep[a_1] - (1 << i) >= dep[b_1]:
            a_1 = fa[a_1][i]
    if a_1 != b_1:
        return 0
    elif a == a_1:
        return 1
    elif b == a_1:
        return 2


dfs(root, 0)
for _ in range(int(input())):
    x, y = map(int, input().split())
    print(lca(x, y))