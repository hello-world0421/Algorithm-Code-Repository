n, c = input().split()
n = int(n)
s = input()
if n >= len(s):
    s = c * (n - len(s)) + s
else:
    s = s[-1*n::]
print(s)
