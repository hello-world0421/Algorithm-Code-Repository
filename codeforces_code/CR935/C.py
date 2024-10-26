import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    a = input()
    ans0 = []
    for i in range(n):
        x1 = a[:i+1]
        x2 = a[i+1:]
        if x1.count('0') >= x2.count('1') and x2.count('0') >= x1.count('1'):
            ans0.append(i+1)
    ans0 = [abs(i-n//2) for i in ans0]
    ans.append(ans0.index(min(ans0))+1)

sys.stdout.write('\n'.join(map(str, ans)))