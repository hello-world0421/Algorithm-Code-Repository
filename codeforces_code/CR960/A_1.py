from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    frequency = dict(Counter(a))
    for num in sorted(frequency.keys(), reverse=True):
        if frequency[num] & 1:
            print("YES")
            break
    else:
        print("NO")