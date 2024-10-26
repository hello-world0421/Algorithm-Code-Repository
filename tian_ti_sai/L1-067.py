k, a, b = map(float, input().split())
if a == 0:
    if k * 2.455 >= b:
        print(f"{k * 2.455:.2f}", "T_T")
    else:
        print(f"{k * 2.455:.2f}", "^_^")
elif a == 1:
    if k * 1.26 >= b:
        print(f"{k * 1.26:.2f}", "T_T")
    else:
        print(f"{k * 1.26:.2f}", "^_^")
