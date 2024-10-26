import sys


ans = []
for _ in range(int(input())):
    x = list(map(int, input().rstrip()))
    y = list(map(int, input().rstrip()))
    s = n = len(x)
    for i in range(n):
        if x[i] != y[i]:
            if x[i] < y[i]:
                x[i], y[i] = y[i], x[i]
            s = i + 1
            break
    for i in range(s, n):
        if x[i] > y[i]:
            x[i], y[i] = y[i], x[i]
    ans0 = [''.join(map(str, x)), ''.join(map(str, y))]
    ans.append('\n'.join(ans0))

sys.stdout.write('\n'.join(ans))
