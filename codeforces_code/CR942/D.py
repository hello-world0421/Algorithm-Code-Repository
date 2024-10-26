import sys


def gcd(n: int, m: int) -> int:
    return n if m == 0 else gcd(m, n % m)


ans = []
dp = {}
for _ in range(int(input())):
    n, m = map(int, input().split())
    ans0 = 0
    mod = 2000003
    n, m = n % mod, m % mod
    for i in range(1, n+1):
        for j in range(1, m+1):
            if (i, j) in dp:
                ans0 += dp[(i, j)]
                continue
            if ((i + j) % mod) % ((j * gcd(i, j)) % mod) == 0:
                ans0 += 1
                dp[(i, j)] = 1
            else:
                dp[(i, j)] = 0
    ans.append(str(ans0))
sys.stdout.write('\n'.join(ans))
