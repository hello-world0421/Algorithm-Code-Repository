import sys
from math import inf

ans = []
for _ in range(int(input())):
    n, k, pb, ps = map(int, input().split())
    p = list(map(int, input().split()))
    a = list(map(int, input().split()))
    

sys.stdout.write('\n'.join(ans))