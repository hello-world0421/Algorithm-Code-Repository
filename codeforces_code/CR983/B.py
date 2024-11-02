import sys

ans = []
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if n == 1:
        ans.append("1")
        ans.append("1")
    elif k == 1 or k == n:
        ans.append("-1")
    else:
        ans.append("3")
        ans1 = "1"
        ans1 += f" {k - min(k - 2, n - k - 1)}"
        ans1 += f" {k + min(k - 2, n - k - 1) + 1}"
        ans.append(ans1)

sys.stdout.write('\n'.join(ans))