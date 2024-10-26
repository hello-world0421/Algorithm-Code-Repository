import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
inf = 2 ** 61 - 1
mod = 998244353
def solve():
    a, b, c = mi()
    ans = 0
    while a + b + c > 0:
        if c == 0 or (c > 1 and a == 0 and b == 0):
            print(-1)
            return
        ans += 1
        if c == 1 and a == 0 and b == 0:
            break
        ut = min(b, c)
        b -= ut
        c -= ut
        dt = min(a, c // 2)
        a -= dt
        c -= dt * 2
        c += ut + dt
        if ut + dt == 0:
            print(-1)
            return
    print(ans - 1)
        
        
for _ in range(ii()):
    solve()