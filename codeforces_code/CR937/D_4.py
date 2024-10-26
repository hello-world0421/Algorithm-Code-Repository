import sys, random
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
inf = 2 ** 61 - 1
mod = 998244353
r = random.randint(0, inf)
bid = []

for i in range(10 ** 5 + 1):
    if set(str(i)) <= set('01'):
        bid.append(i ^ r)
ok = [0] * (10 ** 5 + 1)

for i in range(10 ** 5 + 1):
    if i ^ r in bid:
        ok[i] = 1
    for v in bid:
        v ^= r
        if i * v > 10 ** 5:
            break
        ok[i * v] |= ok[i]

def solve():
    n = ii()
    if ok[n]:
        print('YES')
    else:
        print('NO')
        
for _ in range(ii()):
    solve()