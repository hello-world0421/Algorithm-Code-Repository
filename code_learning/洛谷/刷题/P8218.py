import sys

n = int(input())
a = [0] + list(map(int, input().split()))
pre_sum = [0]
for i in range(1, n + 1):
    pre_sum.append(pre_sum[-1] + a[i])
for _ in range(int(input())):
    l, r = map(int, input().split())
    sys.stdout.write(str(pre_sum[r] - pre_sum[l - 1]) + '\n')