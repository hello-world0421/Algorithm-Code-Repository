from collections import Counter

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = dict(Counter(map(int, input().split())))
    b = dict(Counter(map(int, input().split())))
    ans = 0
    for num in a.keys():
        ans += min(a.get(num, 0), b.get(num, 0))
    print(ans)