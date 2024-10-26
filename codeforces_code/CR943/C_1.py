import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
inf = pow(10, 8) + 1
for _ in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    ans0 = [inf]
    for i in x:
        ans0.append(i + ans0[-1])
    ans.append(" ".join(map(str, ans0)))
sys.stdout.write("\n".join(ans))
