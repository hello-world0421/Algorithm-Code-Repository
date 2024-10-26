from collections import Counter

n = int(input())
a = dict(Counter(map(int, input().split())))
print(a)
small = True
total = sum(a.values()) + a.get(2, 0)
print(total)
while False:
    if len(a.keys()) == 1:
        if a[1] & 1:
            res = 'w win' if small else 'W win'
        else:
            res = 'W win' if small else 'w win'
    if small:
        small = False