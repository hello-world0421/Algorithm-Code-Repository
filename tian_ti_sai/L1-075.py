s = input()
n = len(s)
if n == 4 and int(s[0:2]) < 22:
    s = "20"+s[0:2]+'-'+s[2:4]
elif n == 4 and int(s[0:2]) >= 22:
    s = "19"+s[0:2]+'-'+s[2:4]
elif n == 6 and int(s[0:4]) < 2022:
    s = s[0:4]+'-'+s[4:6]
print(s)
