n = int(input())
love = {}
for i in range(n):
    tag = input().split()
    for j in range(1, len(tag)):
        tag[j] = int(tag[j])
        if tag[j] not in love:
            love[tag[j]] = 1
        else:
            love[tag[j]] += 1
love = sorted(love.items(), key=lambda x: (x[1], x[0]), reverse=True)
x, y = love[0]
print(x, y)
