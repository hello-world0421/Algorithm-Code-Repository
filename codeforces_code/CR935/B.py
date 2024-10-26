import sys

ans = []
for _ in range(int(input())):
    a, b, m = map(int, input().split())
    n = 0
    if m % a == 0:
        n += m // a + 1
    else:
        n += (m + a - 1) // a
    if m % b == 0:
        n += m // b + 1
    else:
        n += (m + b - 1) // b
    ans.append(n)
sys.stdout.write('\n'.join(map(str, ans)))
