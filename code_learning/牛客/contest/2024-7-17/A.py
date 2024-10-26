# 数学思维题，主要就是找规律
import sys
input = lambda: sys.stdin.readline().rstrip()

ans = 0
n = int(input())
while n != 0:
    if n <= 4:
        if n in (1, 2):
            ans += 1
            break
        elif n in (3, 4):
            ans += 2
            break
    elif n & 1:
        n -= 1
        ans += 1
    elif not n & 1:
        n /= 2
        ans += 1
    # elif n & 1 == 0:
    #     n /= 2
    #     ans += 1
    # elif n & 1 != 0:
    #     n -= 1
    #     ans += 1

sys.stdout.write(str(ans))