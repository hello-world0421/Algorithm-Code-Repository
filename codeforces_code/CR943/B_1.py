import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
ans = []
for _ in range(t):
    n, m = map(int, input().split())
    a = list(input().rstrip())
    b = list(input().rstrip())
    ans0 = 0
    for i in b:
        if a[ans0] == i:
            ans0 += 1
        if ans0 == n:
            break
    ans.append(ans0)
sys.stdout.write("\n".join(map(str, ans)))