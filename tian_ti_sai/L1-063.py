n = int(input())
for i in range(n):
    sex, h, w = map(int, input().split())
    if sex == 1:
        if h == 130:
            print("wan mei!", end=" ")
        elif h > 130:
            print("ni li hai!", end=" ")
        elif h < 130:
            print("duo chi yu!", end=" ")
        if w == 27:
            print("wan mei!")
        elif w > 27:
            print("shao chi rou!")
        elif w < 27:
            print("duo chi rou!")
    elif sex == 0:
        if h == 129:
            print("wan mei!", end=" ")
        elif h > 129:
            print("ni li hai!", end=" ")
        elif h < 129:
            print("duo chi yu!", end=" ")
        if w == 25:
            print("wan mei!")
        elif w > 25:
            print("shao chi rou!")
        elif w < 25:
            print("duo chi rou!")
