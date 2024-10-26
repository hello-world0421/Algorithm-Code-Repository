a, b = input().split()
a = int(a)
b = int(b)
if b == 0:
    print(f"{a}/{b}=Error")
elif b < 0:
    print(f"{a}/({b})={a/b:.2f}")
else:
    print(f"{a}/{b}={a/b:.2f}")
