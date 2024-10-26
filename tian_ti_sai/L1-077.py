xin = list(map(int, input().split()))
temp = int(input())
while 0 <= temp <= 23:
    if xin[temp] > 50:
        print(f"{xin[temp]} Yes")
    else:
        print(f"{xin[temp]} No")
    temp = int(input())
