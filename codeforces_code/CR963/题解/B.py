"""
思维题 + 贪心
时间复杂度 O(nlogn)
"""
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    s = -1
    v = []
    for x in a:
        if x & 1 == 0:
            v.append(x)
        elif x > s:
            s = x
    v.sort()

    if s == -1 or v == []:
        print(0)
        continue

    ans = len(v)
    for t in v:
        if t < s:
            s += t
        else:
            ans += 1
            break
    
    print(ans)