from collections import Counter


for _ in range(int(input())):
    n, k = map(int, input().split())
    c = dict(Counter(map(int, input().split())))
