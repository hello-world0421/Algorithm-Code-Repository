w, h = map(float, input().split())
num = w / h ** 2
if num > 25:
    flag = "PANG"
else:
    flag = "Hai Xing"
print(f"{num:.1f}\n{flag}")
