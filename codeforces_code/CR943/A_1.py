import math
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    x = int(input())
    ma = 0
    for i in range(1, x):
        u = math.gcd(x, i) + i
        if ma < u:
            ans0, ma = i, u
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))