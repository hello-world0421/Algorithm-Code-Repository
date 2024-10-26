import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    pre = a.copy()
    while True:
        for i in range(n - 1):
            a[i + 1] = min(0, a[i + 1] - a[i])
        a[0] = min(0, a[0] - a[n - 1])
        if a == pre:
            break
        pre = a.copy()
    m = len(a) - a.count(0)
    ans.append(str(m))
    if m == 0:
        ans.append(None)
    else:
        ans.append(' '.join([str(i + 1) for i, x in enumerate(a) if x > 0]))
sys.stdout.write('\n'.join(ans))
