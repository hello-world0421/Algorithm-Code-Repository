c, n = map(str, input().split())
n = int(n)
chinese = [[0 for j in range(n)] for i in range(n)]
for i in range(n):
    temp = input()
    for j in range(n):
        if temp[j] == ' ':
            chinese[i][j] = 0
        else:
            chinese[i][j] = 1

temp = [row.copy() for row in chinese]
temp.reverse()
for row in temp:
    row.reverse()
    
if temp == chinese:
    print("bu yong dao le")
for i in range(n):
    for j in range(n):
        if temp[i][j] == 1:
            print(c, end='')
        elif temp[i][j] == 0:
            print(' ', end='')
    print()
