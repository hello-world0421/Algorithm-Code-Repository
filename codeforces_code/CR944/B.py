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
    s = input()
    if len(set(s)) == 1:
        no()
        continue
    else:
        yes()
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                if s[i] != s[j]:
                    ans.append(s[0:i] + s[j] + s[i+1:j] + s[i] + s[j+1:])
                    break
            else:
                continue
            break
sys.stdout.write('\n'.join(map(str, ans)))