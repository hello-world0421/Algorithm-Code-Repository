n = int(input())
s = input()
result = []
for i in range(len(s)):
    if len(result) < n:
        result.append(list(s[i]))
    else:
        result[i % n].insert(0, s[i])
for i in range(n):
    if len(result[i]) < len(result[0]):
        result[i].insert(0, ' ')
    print(''.join(result[i]))
