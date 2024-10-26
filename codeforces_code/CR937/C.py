t = int(input())

for _ in range(t):
    h, m = map(int, input().split(':'))
    if 12 <= h <= 23:
        sign = 'PM'
        if h != 12:
            h -= 12
    else:
        sign = 'AM'
        if h == 0:
            h = 12
    print(f"{h:02d}:{m:02d} {sign}")
