import sys

input = lambda: sys.stdin.readline().rstrip()

ans = []
for _ in range(int(input())):
    n = int(input())
    adj = {num: [] for num in range(n + 1)}

    for _ in range(n - 1):
        x, y = map(int, input().split())
        adj[x].append(y)
        adj[y].append(x)
    
    sz = {num: 0 for num in range(n + 1)}
    mss = {num: 0 for num in range(n + 1)}
    ctr = []
    def dfs(p, fa=0):
        sz[p], mss[p] = 1, 0
        for s in adj[p]:
            if s != fa:
                dfs(s, p)
                mss[p] = max(mss[p], sz[s])
                sz[p] += sz[s]
        mss[p] = max(mss[p], n - sz[p])
        if mss[p] <= n / 2:
            ctr.append(p)
    dfs(1)
    if len(ctr) == 1:
        ans.append(f"{ctr[0]} {adj[ctr[0]][0]}")
        ans.append(f"{ctr[0]} {adj[ctr[0]][0]}")
    elif len(ctr) == 2:
        if adj[ctr[0]][0] != ctr[1]:
            ans.append(f"{ctr[0]} {adj[ctr[0]][0]}")
            ans.append(f"{ctr[1]} {adj[ctr[0]][0]}")
        else:
            ans.append(f"{ctr[0]} {adj[ctr[0]][1]}")
            ans.append(f"{ctr[1]} {adj[ctr[0]][1]}")

sys.stdout.write('\n'.join(map(str, ans)))