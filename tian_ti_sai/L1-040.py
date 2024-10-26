n = int(input())
for i in range(n):
    sex, h = input().split()
    h = float(h)
    if sex == 'M':
        print(f"{h / 1.09:.2f}")
    else:
        print(f"{h * 1.09:.2f}")
