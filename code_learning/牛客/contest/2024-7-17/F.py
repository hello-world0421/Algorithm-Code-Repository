import sys
from functools import reduce
input = lambda: sys.stdin.readline().rstrip()

ans = 0
n = int(input())
a = [0] + list(map(int, input().split()))
xor_sum = reduce(lambda x, y: x ^ y, a)
# 时间复杂度：sum(n//i) from 1 to n 等价于 n * logn
for i in range(1, n + 1):
    for j in range(1, n // i + 1):
        ans = max(ans,
                  xor_sum ^ a[i] ^ (a[i] + j),
                  xor_sum ^ a[i] ^ (a[i] * j),
                  )

sys.stdout.write(str(ans))