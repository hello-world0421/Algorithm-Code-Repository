polys: list[int] = list(map(int, input().split()))
d_polys: list[int] = []

for i in range(0, len(polys), 2):
    d_polys.append(polys[i] * polys[i + 1])
    if polys[i + 1] != 0:
        d_polys.append(polys[i + 1] - 1)
    else:
        d_polys.append(polys[i + 1])
if len(d_polys) > 2 and d_polys[-2:] == [0, 0]:
    d_polys = d_polys[:-2]
print(*d_polys)
