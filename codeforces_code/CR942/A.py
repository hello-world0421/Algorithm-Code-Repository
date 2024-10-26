import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    i, ans0 = 0, 0
    while i < n:
        if a[i] > b[i]:
            ans0 += 1
            a.insert(i, b[i])
        else:
            i += 1
    ans.append(str(ans0))
sys.stdout.write('\n'.join(ans))
