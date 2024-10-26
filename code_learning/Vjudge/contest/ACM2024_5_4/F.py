import sys
from math import inf

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    al, bo, limit, turn = 0, 0, 0, 0
    alice = True
    while a:
        turn += 1
        t = 0
        if alice:
            while t <= limit and a:
                t += a.pop(0)
            al += t
            alice = False
            if not a:
                break
        else:
            while t <= limit and a:
                t += a.pop()
            bo += t
            alice = True
            if not a:
                break
        limit = t
    ans.append(' '.join(map(str, [turn, al, bo])))

sys.stdout.write('\n'.join(ans))