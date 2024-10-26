import sys

ans = []
for _ in range(int(input())):
    n, s, v = map(int, input().split())
    ans.append(str(1 if n <= s * v else 0))
sys.stdout.write('\n'.join(ans))
