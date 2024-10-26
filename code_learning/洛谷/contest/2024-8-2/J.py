n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i in range(len(a)):
    c.append([i, a[i]])
c = sorted(c, key=lambda x: x[1])
temp = []
for i in range(len(c)):
    temp.append(c[i] if i == 0 else [c[i][0], c[i][1] - c[i - 1][1]])
temp = sorted(temp, key=lambda x: x[0])
ans = 0
d = [0] * len(a)
for i in range(len(temp)):
    d[i] = (temp[i][1] if i == 0 else temp[i][1] + d[i - 1])
for i, score in temp:
    ans += d[i] + b[i] * 20
print(ans)