# 涉及long long类型的数据量太大，Python会变得奇慢无比
import sys

input = lambda: sys.stdin.readline().rstrip()

ans = 0
n, m, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
for i in range(1, n + 1):
    if sum(a[:i]) > m:
        if i - 1 + k >= n:
            ans = n
        else:
            ans = i - 1

sys.stdout.write(str(ans))