import sys
mod = 12345678910

cnt = ans = 0
n = int(input())
a = list(map(int, sys.stdin.read().split()))
for i in range(n):
    if a[i] == 0:
        cnt += 1
    else:
        cnt -= 1
        if a[i - 1] == 0:
            ans += pow(2, cnt, mod)
sys.stdout.write(str(ans % mod))