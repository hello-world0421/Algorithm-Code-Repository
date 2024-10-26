import sys

ans = []
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    n = a + b // 3
    if b % 3:
        if b % 3 + c > 2:
            n += 1
            c -= 3 - b % 3
            n += (c + 3 - 1) // 3
        else:
            n = -1
    else:
        n += (c + 3 - 1) // 3
    ans.append(n)
sys.stdout.write('\n'.join(map(str, ans)))
    