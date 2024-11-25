sg = [0] * 1000
sg[0] = 0
sg[1] = 1
values = [i * i for i in range(1, 100) if i * i <= 100]
for i in range(1, 101):
    visit = [False] * 1000
    for value in values:
        if value <= i:
            visit[sg[i - value]] = True
        else:
            break
    for j in range(1000):
        if not visit[j]:
            sg[i] = j
            break
for i in range(1, 101):
    print(f"{i}:{sg[i]}")