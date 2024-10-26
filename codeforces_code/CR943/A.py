from math import inf, gcd
import sys
input = lambda: sys.stdin.readline().rstrip()
mod = 998244353

ans = []
for _ in range(int(input())):
    x = int(input())
    ma, dex = 2, 1
    for i in range(2, x):
        if (num := gcd(i, x) + i) > ma:
            dex, ma = i, num
    ans.append(dex)

sys.stdout.write('\n'.join(map(str, ans)))