import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans0 = 0
    for num in set(a):
        ans0 += a.count(num) // 3
    ans.append(ans0)
sys.stdout.write('\n'.join(map(str, ans)))
