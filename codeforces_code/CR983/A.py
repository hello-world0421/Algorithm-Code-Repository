import sys

ans = []

t = int(input())
for _ in range(t):
    n = int(input())
    a = sum(map(int, input().split()))
    ans1 = a % 2
    ans2: int
    if a == 0:
        ans2 = 0
    elif 0 < a <= n:
        ans2 = a
    else:
        ans2 = 2 * n - a
    ans.append(f"{ans1} {ans2}")

sys.stdout.write('\n'.join(ans))