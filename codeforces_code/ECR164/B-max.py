import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if min(a) == max(a):
        ans0 = -1
    else:
        u = [-1] + [i for i, x in enumerate(a) if x ^ a[0]] + [n]
        ans0 = min(u[i+1] - u[i] - 1 for i in range(len(u)-1))
    ans.append(ans0)
sys.stdout.write('\n'.join(map(str, ans)))
