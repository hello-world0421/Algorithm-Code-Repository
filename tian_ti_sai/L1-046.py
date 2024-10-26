x = int(input())
p11 = 1
while True:
    if p11 % x == 0 and p11 >= x:
        break
    else:
        p11 = int(str(p11) + '1')
s = p11 // x
n = len(str(p11))
print(s, n)
