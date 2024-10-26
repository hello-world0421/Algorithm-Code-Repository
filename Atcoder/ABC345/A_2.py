s = input()
flag = True
if s[0] != '<':
    flag = False
if s[-1] != '>':
    flag = False
for i in range(1, len(s)-1):
    if s[i] != '=':
        flag = False
if flag:
    print("Yes")
else:
    print("No")
