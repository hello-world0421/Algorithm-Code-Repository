for _ in range(int(input())):
    num = input()
    if (1 <= int(num) <= 10):
        print("NO")
        continue
    if (len(num) >= 2 and int(num[:2]) == 10 and int(num[2:]) >= 2 and num[2] != '0'):
        print("YES")
    else:
        print("NO")