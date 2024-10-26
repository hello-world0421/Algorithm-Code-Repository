import sys

ans = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = input()
    b = input()
    ans0 = 0
    for num in b:
        if a[ans0] == num:
            ans0 += 1
        if ans0 == n:
            break
    ans.append(str(ans0))

sys.stdout.write('\n'.join(ans))