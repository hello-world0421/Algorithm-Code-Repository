import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
inf = 2 ** 61 - 1
mod = 998244353
def solve():
    n = ii()
    s = [ord(v) - ord('a') for v in input()]
    for i in range(1, n + 1):
        if n % i:
            continue
        f = 0
        for j in range(i):
            sset = [0] * 26
            for k in range(j, n, i):
                sset[s[k]] += 1
            if max(sset) + 1 < sum(sset):
                f += 2
                break
            if max(sset) + 1 == sum(sset):
                f += 1
            else:
                pass
        if f <= 1:
            print(i)
            return
    
            
        
for _ in range(ii()):
    solve()