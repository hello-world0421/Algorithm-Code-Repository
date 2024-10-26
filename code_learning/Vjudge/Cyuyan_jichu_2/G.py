import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    while n & 1 == 0:
        n >>= 1
    if not (n ^ 1) or not (n ^ 3):
        ans.append('0')
    else:
        ans.append('1')

sys.stdout.write('\n'.join(ans))
