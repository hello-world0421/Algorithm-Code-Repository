import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
inf = 2 ** 61 - 1
mod = 998244353
def solve():
    n = ii()
    songs = [input().split() for _ in range(n)]
    graph = [[] for _ in range(n)]
    
    for i in range(n):
        for j in range(i + 1, n):
            if songs[i][0] == songs[j][0] or songs[i][1] == songs[j][1]:
                graph[i].append(j)
                graph[j].append(i)
    
    dp = [[False] * n for _ in range(1 << n)]
    for i in range(n):
        dp[1 << i][i] = True
        
    for mask in range(1, 1 << n):
        for i in range(n):
            if mask & (1 << i):
                for j in graph[i]:
                    if mask & (1 << j):
                        dp[mask][i] |= dp[mask ^ (1 << i)][j]
    
    bit_count = [0] * (1 << n)
    ans = 0
    for mask in range(1, 1 << n):
        bit_count[mask] = bit_count[mask >> 1] + (mask & 1)
        if sum(dp[mask]):
            ans = max(ans, bit_count[mask])
    
    print(n - ans)
        
for _ in range(ii()):
    solve()