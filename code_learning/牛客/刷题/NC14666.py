import sys

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
           cnt += 1
           if a[i] < a[j]:
               break
    sys.stdout.write(str(cnt))