import sys
from math import inf, gcd, lcm
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
si = lambda: input()
mod = 998244353

mul = False
ans = 0
t = 1
if mul:
    t = int(input())
for _ in range(t):
    n = int(input())
    root = 'polycarp'
    adj = {}

    for _ in range(n):
        s = input().split()
        s[0], s[2] = s[0].lower(), s[2].lower()
        adj.setdefault(s[2], []).append(s[0])
        adj.setdefault(s[0], []).append(s[2])
    dep = {person: 0 for person in adj.keys()}

    def dfs(p, fath):
        dep[p] = dep[fath] + 1
        for s in adj[p]:
            if s != fath:
                dfs(s, p)
    dfs(root, root)
    ans = max(dep.values())

sys.stdout.write(str(ans))