import sys
from math import inf
input = lambda: sys.stdin.readline().rstrip()


n = int(input())
adj = {num: [] for num in range(1, n + 1)}
for __ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
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
        if fa[a][i] != fa[a][i]:
            a, b = fa[a][i], fa[b][i]
    return fa[a][0]
dfs(1, 0)
ans1 = inf
ans1_index = 0
dp = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(i, n + 1):
        if i != j:
            dp[j][i] = dp[i][j] = dep[i] + dep[j] - 2 * dep[lca(i, j)]

for i in range(1, n + 1):
    if ans1 > (res := sum(dp[i])):
        ans1 = res
        ans1_index = i

sys.stdout.write(f"{ans1_index} {ans1}")