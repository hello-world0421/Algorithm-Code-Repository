a = []
for i in range(1000):
    if (5 ** i <= 9223372036854775807):
        a.append(5 ** i)
print(*a, sep=', ')
print(len(a))