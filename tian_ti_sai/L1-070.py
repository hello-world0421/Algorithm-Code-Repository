s = input()
flag = 0
i = 0
num = 0
while s != ".":
    num += 1
    if flag == 0:
        i += 1
    if "chi1 huo3 guo1" in s:
        flag += s.count("chi1 huo3 guo1")
    s = input()
print(num)
if flag != 0:
    print(i, flag)
else:
    print("-_-#")
