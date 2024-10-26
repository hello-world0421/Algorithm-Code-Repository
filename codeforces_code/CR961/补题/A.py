def solve():
    n, k = map(int, input().split())
    a, b = n, n - 1
    ans = 0
    while k > 0:
        ans += 1
        k -= a
        a, b = b, (b if a != b else b - 1)
    print(ans)

for _ in range(int(input())):
    solve()