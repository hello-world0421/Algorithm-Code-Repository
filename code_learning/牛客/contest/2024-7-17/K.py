import sys

input = lambda: sys.stdin.readline().rstrip()



ans = 0

n, m = map(int, input().split())
for _ in range(m):
    u, v = map(int, input().split())
# if n & 1 == 0:
#     ans = int((n / 2) ** 2)
# else:
#     temp = n // 2
#     ans = int(temp * (n - temp))
if not n & 1:
    ans = (n // 2) * (n // 2)
else:
    ans = (n // 2) * (n // 2 + 1)

sys.stdout.write(str(ans))