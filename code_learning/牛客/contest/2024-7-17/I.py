# 索引的循环技巧
import sys

input = lambda: sys.stdin.readline().rstrip()


ans = 0
n, t = map(int, input().split())
a = list(map(int, input().split()))
new_a = a[0:1] + a[1:][::-1]
# if t > n:
#     t = n
t = min(t, n)
ans = new_a.index(max(new_a[:t+1]))

sys.stdout.write(str(ans))