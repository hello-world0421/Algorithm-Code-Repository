from math import log

for _ in range(int(input())):
    l, r = map(int, input().split())
    ans = (int(log(l, 3)) + 1) * 2
    for i in range(l + 1, r + 1):
        ans += int(log(i, 3)) + 1
    print(ans)