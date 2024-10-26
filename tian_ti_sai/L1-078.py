n, m = map(int, input().split())
num =  0
for i in range(n):
    s = input()
    if "easy" in s or "qiandao" in s:
        continue
    else:
        num += 1
        if num > m:
            print(s)
            break
if num <= m:
    print("Wo AK le")
