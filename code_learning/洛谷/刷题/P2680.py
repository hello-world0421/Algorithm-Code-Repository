import sys
from math import inf, gcd, lcm
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
si = lambda: input()
yes = lambda: ans.append('YES')
no = lambda: ans.append('NO')
mod = 998244353

t, multy = 1, False
ans = []
if multy:
    t = int(input)
for _ in range(t):
    n, m = map(int, input().split())
    adj = {num: {0: 0} for num in range(n + 1)}
    for _ in range(n - 1):
        u, v, w = map(int, input().split())
        adj[u][v] = w
        adj[v][u] = w
    dep = [0] * (n + 1)
    cost = [0] * (n + 1)
    fa = [[0] * 30 for _ in range(n + 1)]

    def dfs(p, fath=0):
        dep[p] = dep[fath] + 1
        cost[p] = cost[fath] + adj[p][fath]
        fa[p][0] = fath
        i = 1
        while (1 << i) <= dep[p]:
            fa[p][i] = fa[fa[p][i - 1]][i - 1]
            i += 1
        for s in adj[p].keys():
            if s != fath:
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
    
    dfs(1)
    print(adj)
    path = []
    for i in range(m):
        path.append(list(map(int, input().split())))
    max_time = 0
    for i in range(len(path)):
        a, b = path[i]
        max_time = max(max_time, cost[a] + cost[b] - 2 * cost[lca(a, b)])

sys.stdout.write('\n'.join(map(str, ans)))