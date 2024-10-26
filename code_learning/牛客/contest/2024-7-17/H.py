import sys

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
a = list(map(int, input().split()))
ans = sum(a)
num1 = max(a) * (n - 1)
num2 = n
ans += num2 if num1 <= num2 else num1
# if num1 <= num2:
#     ans += num2
# else:
#     ans += num1

sys.stdout.write(str(ans))