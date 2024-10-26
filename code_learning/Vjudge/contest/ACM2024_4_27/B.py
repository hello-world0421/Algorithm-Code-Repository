import sys

k = int(input())
a = list(map(int, input().split()))
n, m, x = map(int, input().split())
b, ans = [x], 0
for i in range(1, n+1):
    b.append(b[i - 1] + a[(i - 1) % k])
    if b[i-1] % m <= b[i] % m:
        ans += 1
sys.stdout.write(str(ans))
