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

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans2 = []
    for i in range(len(a)):
        ans1 = 0
        temp = a.copy()
        temp.pop(i)
        for i in range(len(temp)):
            for j in range(i, len(temp)):
                ans1 += min(temp[i:j+1])
        ans2.append(str(ans1))
    ans.append(' '.join(ans2))

sys.stdout.write('\n'.join(ans))