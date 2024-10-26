import sys

ans = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    if n == 1:
        ans.append([k])
        continue
    ans0 = []
    temp = k
    l = k.bit_length()
    for num in range(l-1, -1, -1):
        if k - (1 << num) >= n-1:
            ans0.append(1 << num)
            n -= 1
            k -= 1 << num
    while len(ans0) < n - 1:
        ans0.append(1)
        n -= 1
    if n == 1:
        ans0.append(temp - sum(ans0))
    ans.append(ans0)

sys.stdout.write('\n'.join([' '.join(map(str, a)) for a in ans]))