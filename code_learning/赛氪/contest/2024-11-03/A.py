a = []
for i in range(1000):
    if (3 ** i <= 1e19):
        a.append(3 ** i)
print(*a, sep=', ')
print(len(a))