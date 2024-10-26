import sys
from math import inf

ans = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    ans.append(str(k + (k - 1) // (n - 1)))
sys.stdout.write('\n'.join(ans))