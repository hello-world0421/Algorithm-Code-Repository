import sys

ans = []
for i in range(int(input())):
    n, m, k = map(int, input().split())
    # c = n // m + (n % m > 0)
    c = (n + m - 1) // m
    ans.append("YES" if n - c > k else "NO")

sys.stdout.write("\n".join(ans))