import sys
from math import inf

ans = []
for _ in range(int(input())):
    n1, n2 = map(int, input().split())
    if n1 == 0:
        ans.append('1')
    elif n2 == 0:
        ans.append(str(n1 +1))
    else:
        ans.append(str(n1 + n2 * 2 + 1))

sys.stdout.write('\n'.join(ans))